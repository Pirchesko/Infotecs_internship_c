#pragma once

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketManager {
public:
    SocketManager();
    ~SocketManager();
    void closeSocket();

protected:
    std::string ip;
    int port;
    int sock;
    struct sockaddr_in address;
};