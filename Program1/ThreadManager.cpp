#include "ThreadManager.h"

// Глобальная переменная чтобы можно было завершить программу по Ctrl+C
ThreadManager* g_threadManager = nullptr;
void signalHandler(int signum) {
    if (g_threadManager) {
        g_threadManager->stop();
    }
}

SocketClient socketClient;

ThreadManager::ThreadManager() {
    stopFlag = false;
    if (!socketClient.connectToServer()) {
        std::cout << "Failed to connect to Program 2" << std::endl;
    }
}

ThreadManager::~ThreadManager() {
    stop();
}

void ThreadManager::start() {
    inputerThread = std::thread(&ThreadManager::inputer, this);
    readerThread = std::thread(&ThreadManager::reader, this);
}

void ThreadManager::stop() {
    stopFlag = true;
    cv.notify_all();
    if (readerThread.joinable()) {
        readerThread.join();
    }
    if (inputerThread.joinable()) {
        inputerThread.join();
    }
}

bool ThreadManager::isStopped() {
    return stopFlag;
}

void ThreadManager::inputer() {
    std::cout << "[Program: 1][Thread: 1] Started! (inputer)" << std::endl;
    while (!stopFlag) {
        // Микро задержка просто для того чтобы cout на следующей строке вывелся
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::string inputData;
        std::cout << "[Program: 1][Thread: 1] Write string with only digits (max 64 symbols): ";
        std::cin >> inputData;
        
        if (inputData.length() > 64) {
            std::cout << "[Program: 1][Thread: 1] Error: string is more than 64 symbols!" << std::endl;
            continue;
        }
        bool onlyDigits = true;
        for (int i = 0; i < inputData.length(); i++) {
            if (inputData[i] < '0' || inputData[i] > '9') {
                onlyDigits = false;
                break;
            }
        }
        if (!onlyDigits) {
            std::cout << "[Program: 1][Thread: 1] Error: bad symbol - string must be have only digits!" << std::endl;
            continue;
        }

        StringTools::sortAndReplace(inputData);
        {
            std::unique_lock<std::mutex> lock(mtx);
            buffer.push(inputData);
        }
        cv.notify_one();
    }
    std::cout << "[Program: 1][Thread: 1] Stopped! (inputer)" << std::endl;
}

bool ThreadManager::checkBuffer() {
    return !buffer.empty() || stopFlag;
}

void ThreadManager::reader() {
    // Микро задержка просто для того чтобы cout на старте на следующей строчке вывелся
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "[Program: 1][Thread: 2] Started! (reader)" << std::endl;
    while (!stopFlag) {
        std::string readData;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return checkBuffer(); });
            if (stopFlag && buffer.empty()) {
                break;
            }
            readData = buffer.front();
            buffer.pop();
        }
        std::cout << "[Program: 1][Thread: 2] Readed: " << readData << std::endl;
        int sum = StringTools::calculateSum(readData);
        std::cout << "[Program: 1][Thread: 2] Sum digits: " << sum << std::endl;

        // Передача в программу 2
        socketClient.sendData(std::to_string(sum));
    }
    std::cout << "[Program: 1][Thread: 2] Stopped! (reader)" << std::endl;
}