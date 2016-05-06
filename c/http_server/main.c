#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include <sys/types.h>

#include <errno.h>
#include <string.h>

#include <stdlib.h>

#include <arpa/inet.h>

int main(int argc, char const* argv[])
{
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address = {
        AF_INET,
        htons(3333),
        {
            INADDR_LOOPBACK
        }
    };

    bind(tcp_socket, (struct sockaddr *) &server_address, sizeof server_address);
    listen(tcp_socket, 10);

    if (errno == -1) {
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client_address = {
        AF_INET,
        htons(3333),
        {
            INADDR_ANY
        }
    };

    size_t len = sizeof client_address;

    while (1) {
        int client_socket = accept(tcp_socket, (struct sockaddr *) &client_address, (socklen_t *) &len);

        void *buffer = malloc(250);

        recv(client_socket, buffer, sizeof buffer, MSG_WAITALL);

        printf("%s\n", (char *) buffer);
    }

    return 0;
}
