project(Library)

# Создание динамической библиотеки
add_library(Library SHARED Library.cpp)

# Библиотека использует заголовочные файлы
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})