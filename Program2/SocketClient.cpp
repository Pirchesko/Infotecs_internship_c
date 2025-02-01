#include "SocketClient.h"

SocketClient::SocketClient() : SocketManager() {
}

bool SocketClient::connectToServer() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "Error initializing socket" << std::endl;
        return false;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &address.sin_addr) <= 0) {
        std::cout << "Error in IP translation to special numeric format" << std::endl;
        closeSocket();
        return false;
    }

    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cout << "Connection to Server failed" << std::endl;
        closeSocket();
        return false;
    }

    std::cout << "Connection to Server successful!" << std::endl;
    return true;
}

bool SocketClient::reconnect() {
    closeSocket(); // Закрываем текущее соединение, если оно есть
    return connectToServer(); // Пытаемся подключиться снова
}

void SocketClient::sendData(const std::string& data) {
    if (sock == -1) {
        connectToServer();
    }

    // Проверяем, подключен ли сокет
    int error;
    socklen_t len = sizeof(error);
    if (getsockopt(sock, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
        std::cerr << "Error getting socket options: " << std::strerror(errno) << std::endl;
        return;
    }

    // Если сокет уже закрылся у сервера а мы всё равно пытаемся отправить...
    if (error != 0) {
        std::cerr << "Socket error: " << std::strerror(error) << std::endl;
        // Пытаемся переподключиться
        if (!reconnect()) {
            std::cout << "Failed to reconnect to server. Skip data." << std::endl;
            return;
        }
    }

    // Если сокет в порядке, отправляем данные
    ssize_t bytesSent = send(sock, data.c_str(), data.size(), 0);
    if (bytesSent == -1) {
        std::cout << "Error in send data. Skip data." << std::endl;
    }
    else {
        std::cout << "Bytes send to Server: " << bytesSent << std::endl;
    }
}