#include <stdio.h>

#include <sys/socket.h>
#include <netdb.h>

#include <unistd.h>

int main(void)
{
    int client = socket(AF_INET, SOCK_STREAM, 0);
    struct addrinfo *res;
    struct addrinfo hints;
    hints.ai_protocol = 0;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("rlc.ninja", "http", &hints, &res);

    int conn = connect(client, res->ai_addr, sizeof *res->ai_addr);
    char buf[] = "GET / HTTP/1.1\n"
                 "Host: www.rlc.ninja\n"
                 "Content-Length: 0\n"
                 "\n";
    send(client, (void *) buf, sizeof buf, 0);

    char recvbuf[512];
    while (read(client, (void *) &recvbuf, sizeof recvbuf)) {
        printf("%s\n", recvbuf);
    }

    close(client);
    return 0;
}
