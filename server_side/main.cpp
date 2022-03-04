#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int server_sockfd, client_sockfd = 0;
    struct sockaddr_in server_address, client_address;
    int server_len, client_len;
    char ch;

    unlink("server_socket");
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = 9345;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

    listen(server_sockfd, 5);

    client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, (socklen_t *)&client_len);

    read(client_sockfd, &ch, 1);
    ch++;
    write(client_sockfd, &ch, 1);

    close(client_sockfd);
}
