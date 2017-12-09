#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>
#include <strings.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main() {
    int sockfd, newsockfd, portno = 9430;

    socklen_t clientLen;

    char buffer[BUFFER_SIZE];

    struct sockaddr_in server_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    server_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        exit(2);
    }

    listen(sockfd, 5);

    clientLen = sizeof(cli_addr);

    while (true) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clientLen);

        if (newsockfd < 0) {
            exit(3);
        }

        send(newsockfd, R"({"test": "hola!"})", 21, 0);

        bzero(buffer, BUFFER_SIZE);

        auto n = read(newsockfd, buffer, BUFFER_SIZE-1);

        if (n < 0) {
            exit(4);
        }

        std::cout << buffer << std::endl;
    }

    close(newsockfd);
    close(sockfd);
}