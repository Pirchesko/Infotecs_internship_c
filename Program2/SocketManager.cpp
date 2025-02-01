#include "SocketManager.h"

SocketManager::SocketManager() {
    ip = "127.0.0.1";
    port = 8888;
    sock = -1;
}

SocketManager::~SocketManager() {
    closeSocket();
}

void SocketManager::closeSocket() {
    if (sock != -1) {
        close(sock);
        sock = -1;
        std::cout << "Socket close" << std::endl;
    }
    else {
        std::cout << "Socket is already closed" << std::endl;
    }
}