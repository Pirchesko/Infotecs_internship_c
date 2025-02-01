#pragma once

#include "SocketManager.h"
#include <csignal>

class SocketServer : public SocketManager {
public:
    SocketServer();
    bool bindAndListen();
    int acceptConnection();
    std::string receiveData(int clientSock);
};

extern SocketServer* g_socketServer;
void signalHandler(int signum);