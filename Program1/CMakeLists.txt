project(Program1)

# Создаем исполняемый файл
add_executable(Program1 Program1.cpp ThreadManager.cpp)

# Связываем библиотеку с программой
target_link_libraries(Program1 PRIVATE Library)

# Программа 1 зависит от заголовков из Library
target_include_directories(Program1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ../Library)

# Добавляем исходные файлы для SocketClient и SocketManager
target_sources(Program1 PRIVATE
    ../Program2/SocketClient.cpp
    ../Program2/SocketManager.cpp
)