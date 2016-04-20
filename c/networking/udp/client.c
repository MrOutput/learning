#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#include <unistd.h>

int main(int argc, char *argv[]) {
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket made: %d\n", udp_socket);

    struct sockaddr_in address;
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.0.23");
    address.sin_port = htons(3333);

    int connection = connect(udp_socket, (struct sockaddr *) &address, sizeof address);

    if (connection == 0) {
        char message[] = "Whats up man!";
        printf("Sending message: %s\n", message);

        send(udp_socket, (void *) message, sizeof message, MSG_WAITALL);

        sleep(10);
        shutdown(udp_socket, 2);
    } else {
        return 1;
    }


    return 0;
}
