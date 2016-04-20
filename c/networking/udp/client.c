#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]) {
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in address = {
        AF_INET,
        htons(3333),
        {
            inet_addr("127.0.0.1"),
        }
    };

    int connection = connect(udp_socket, (struct sockaddr *) &address, sizeof address);

    if (connection == 0) {
        char message[] = "Whats up man!";

        send(udp_socket, (void *) message, sizeof message, MSG_WAITALL);
        shutdown(udp_socket, 2);
    } else {
        return 1;
    }


    return 0;
}
