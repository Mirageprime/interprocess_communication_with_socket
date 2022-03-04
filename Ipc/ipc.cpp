#include "ipc.h"

#include <arpa/inet.h>
#include <sys/socket.h>

Ipc::Ipc()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = 9345;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    len = sizeof(address);

}

IpcServer::IpcServer():Ipc(){};

int IpcServer::connect(){
    }

IpcClient::IpcClient():Ipc(){};

int IpcClient::connect(){
    }
