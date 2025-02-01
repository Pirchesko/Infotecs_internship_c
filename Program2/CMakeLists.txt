project(Program2)

# Создаем исполняемый файл
add_executable(Program2 Program2.cpp SocketServer.cpp SocketClient.cpp SocketManager.cpp)

# Указываем, что программа 2 зависит от заголовков из Library
target_include_directories(Program2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ../Library)

# Связываем библиотеку с программой
target_link_libraries(Program2 PRIVATE Library)