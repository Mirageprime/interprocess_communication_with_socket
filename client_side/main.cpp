#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../Ipc/ipc.h"

int main(){
    char ch = 'A';
    int result;

    IpcClient client;

    result = connect(client.sockfd, (struct sockaddr*)&client.address, (socklen_t)client.len);
    if (result != 0){
        std::cout<<"socket connect error"<<errno<<"\n";
    }

    int slen=send(client.sockfd, &ch, sizeof(ch), 0);
    if(slen<0) perror("send error");

    int rlen=recv(client.sockfd, &ch, sizeof(ch), 0);
    if(rlen<0) perror("recv error");

    std::cout<<"char from server  = "<<ch<<"\n";
    close(client.sockfd);

    exit(0);
}
