#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int sockfd;
    struct sockaddr_in address;
    int len;
    int result;
    char ch = 'A';

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = 9345;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    len = sizeof(address);

    result = connect(sockfd, (struct sockaddr*)&address, (socklen_t)len);
    std::cout<<result<<"\n"<<std::endl;
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    std::cout<<"char from server  = "<<ch<<"\n"<<std::endl;
    close(sockfd);
    exit(0);
}
