#pragma once

#include "SocketManager.h"
#include <cstring>

class SocketClient : public SocketManager {
public:
    SocketClient();
    bool connectToServer();
    bool reconnect();
    void sendData(const std::string& data);
};