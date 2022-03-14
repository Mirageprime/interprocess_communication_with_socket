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

    IpcServer server;
    IpcClient client;

    bind(server.sockfd, (struct sockaddr*)&server.address, server.len);

    listen(server.sockfd, 5);
    while(1){
    client.sockfd = accept(server.sockfd, (struct sockaddr*)&client.address, (socklen_t *)&client.len);

    int rlen=recv(client.sockfd, &ch, sizeof(ch), 0);
    if(rlen<0) perror("recv error");

    ch++;

    int slen=send(client.sockfd, &ch, sizeof(ch), 0);
    if(slen<0) perror("send error");

    close(client.sockfd);
    }
}
