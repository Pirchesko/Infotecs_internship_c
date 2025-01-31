#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
#include <string>
#include <csignal>
#include <iostream>
#include "../Library/Library.h"

class ThreadManager {
public:
    ThreadManager();
    ~ThreadManager();
    void start();
    void stop();
    bool isStopped();

private:
    std::atomic<bool> stopFlag;
    std::mutex mtx;
    std::condition_variable cv;
    std::queue<std::string> buffer;
    std::thread inputerThread;
    std::thread readerThread;
    void inputer();
    bool checkBuffer();
    void reader();
};

// Глобальная переменная для SIGINT
extern ThreadManager* g_threadManager;
void signalHandler(int signum);
