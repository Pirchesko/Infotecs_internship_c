#include "Program1.h"
#include "ThreadManager.h"
//#include "../Library/Library.h"

using namespace std;

int main()
{
    ThreadManager threadManager;
    g_threadManager = &threadManager;
    std::signal(SIGINT, signalHandler);

    threadManager.start(); // Запуск потоков

    // Бесконечный цикл, чтобы программа не завершалась
    while (!threadManager.isStopped()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Main thread is stopped" << std::endl;

    return 0;
}