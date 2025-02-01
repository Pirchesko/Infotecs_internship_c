#include "SocketServer.h"

// Глобальная переменная чтобы можно было завершить программу по Ctrl+C
SocketServer* g_socketServer = nullptr;
void signalHandler(int signum) {
    if (g_socketServer) {
        g_socketServer->closeSocket();
    }
    signal(SIGINT, SIG_DFL);
    raise(SIGINT);
}

SocketServer::SocketServer() : SocketManager() {
}

bool SocketServer::bindAndListen() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "Error initializing socket" << std::endl;
        return false;
    }

    // При рестарте порограммы сокет слишком медленно закрыввается и не успвает закрыться
    // Поэтому сделаем возможность использовавть повторно такого же порта и адреса
    // Устанавливаем опцию SO_REUSEADDR
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cout << "Error setting socket options" << std::endl;
        return false;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cout << "Bind failed" << std::endl;
        perror("bind");
        return false;
    }

    if (listen(sock, 3) < 0) {
        std::cout << "Listen failed" << std::endl;
        return false;
    }

    return true;
}

int SocketServer::acceptConnection() {
    int addrlen = sizeof(address);
    return accept(sock, (struct sockaddr*)&address, (socklen_t*)&addrlen);
}

std::string SocketServer::receiveData(int clientSock) {
    char buffer[128] = { 0 };
    int bytesRead = recv(clientSock, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        return ""; // Пустой строкой указываем на закрытие соединения
    }
    return std::string(buffer, bytesRead);
}