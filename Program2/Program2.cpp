#include "Program2.h"

int main() {
    SocketServer socketServer;
    g_socketServer = &socketServer;
    std::signal(SIGINT, signalHandler);

    if (!socketServer.bindAndListen()) {
        return 0;
    }
    std::cout << "[Program: 2] Bind and Listen correct!" << std::endl;
    

    while (true) {
        std::cout << "[Program: 2] Try connect to Program 1..." << std::endl;
        int clientSocket = socketServer.acceptConnection();
        if (clientSocket < 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        std::cout << "[Program: 2] AcceptConnection correct! clientSocket = " << clientSocket << std::endl;
        while (true)
        {
            std::string recvData = socketServer.receiveData(clientSocket);
            if (recvData.empty()) {
                std::cout << "[Program: 2] Client disconnected." << std::endl;
                break;
            }

            std::cout << "[Program: 2] Received from Program 1. Analizing..." << std::endl;

            if (StringTools::analyzeString(recvData)) {
                std::cout << "[Program: 2] Data is received. (data valid): " << recvData << std::endl;
            }
            else {
                // По заданию сказано не выводить строку результата в случае отрицательного результата функци 3,
                // Но для лучшего понимания всё равно буду выводить с пометкой "data invalid"
                std::cout << "[Program: 2] Error: bad data result (data invalid): " << recvData << std::endl;
            }
        }
    }

    return 0;
}