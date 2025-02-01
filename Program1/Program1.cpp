#include "Program1.h"

int main()
{
    ThreadManager threadManager;
    g_threadManager = &threadManager;
    std::signal(SIGINT, signalHandler);

    threadManager.start();

    // Бесконечный цикл, чтобы программа не завершалась
    while (!threadManager.isStopped()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "[Program: 1] Main thread is stopped" << std::endl;

    return 0;
}