#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ADDRESS "127.0.0.1"
#define PORT 3000

int main(int argc, char *argv[]) {
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in address = {
        AF_INET,
        htons(PORT),
        {
            inet_addr(ADDRESS),
        }
    };

    if (bind(udp_socket, (struct sockaddr *) &address, sizeof address) == 0 && listen(udp_socket, 1) == 0) {
        printf("Listening on: %s:%d\n", ADDRESS, PORT);

        char buffer[300];
        struct msghdr msg = {
            &address,
            sizeof address,
            &buffer,
            sizeof buffer
        };

        recvmsg(udp_socket, &msg, MSG_WAITALL);

        //shutdown(udp_socket, 2);
    } else {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
