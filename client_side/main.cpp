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
    std::cout<<result<<"\n"<<std::endl;
    write(client.sockfd, &ch, 1);
    read(client.sockfd, &ch, 1);
    std::cout<<"char from server  = "<<ch<<"\n"<<std::endl;
    close(client.sockfd);
    exit(0);
}
