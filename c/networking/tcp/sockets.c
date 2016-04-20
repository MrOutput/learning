#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
    int sock;
    struct sockaddr_in name;

    sock = socket(PF_INET, SOCK_STREAM, 0); // Create socket

    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Give the socket a name. */
    name.sin_family = AF_INET;
    name.sin_port = htons(3333);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int ssize = sizeof(name);

    if (bind(sock, (struct sockaddr *) &name, ssize) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("Socket is: %d\n", sock);

    printf("Listening status is: %d\n", listen(sock, 1));

    printf("Accepting connection: %d\n",
    accept(sock, (struct sockaddr *) &name, &ssize));

    return 0;
}
