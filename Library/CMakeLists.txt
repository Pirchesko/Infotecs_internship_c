project(Library)

# Создание динамической библиотеки
add_library(Library SHARED Library.cpp)

# Заголовочные файлы в текущей директории будут доступны для других
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})