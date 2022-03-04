#ifndef IPC_H
#define IPC_H

#include <netinet/in.h>

class Ipc
{
public:
    int sockfd;
    struct sockaddr_in address;
    int len;

    virtual int connect() = 0;
    Ipc();
};


class IpcServer : public Ipc
{
public:
    int connect();
    IpcServer();
};


class IpcClient : public Ipc
{
public:
    int connect();
    IpcClient();
};


#endif // IPC_H
