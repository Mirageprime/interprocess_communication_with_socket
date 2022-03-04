#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../Ipc/ipc.h"

int main(){
    char ch;

    unlink("server_socket");

    IpcServer server;
    IpcClient client;

    bind(server.sockfd, (struct sockaddr*)&server.address, server.len);

    listen(server.sockfd, 5);

    client.sockfd = accept(server.sockfd, (struct sockaddr*)&client.address, (socklen_t *)&client.len);

    read(client.sockfd, &ch, 1);
    ch++;
    write(client.sockfd, &ch, 1);

    close(client.sockfd);
}
