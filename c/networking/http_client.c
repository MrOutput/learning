#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

int main(void)
{
    int client = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo *res;
    getaddrinfo("rlc.ninja", "http", NULL, &res);

    int conn = connect(client, res->ai_addr, sizeof *res->ai_addr);
    char req[] = "GET / HTTP/1.1\n"
                 "Host: www.rlc.ninja\n"
                 "Content-Length: 0\n"
                 "\n";
    write(client, req, sizeof req);

    char resp[100];
    while (read(client, &resp, sizeof resp)) {
        printf("%s", resp);
    }

    close(client);
    return 0;
}
