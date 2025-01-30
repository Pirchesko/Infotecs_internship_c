project(Program1)

# Создаем исполняемый файл
add_executable(Program1 "Program1.cpp" "Program1.h")

# Связываем библиотеку с программой
target_link_libraries(Program1 PRIVATE Library)

# Для Visual Studio копирование библиотеки к exe
add_custom_command(TARGET Program1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:Library>
    $<TARGET_FILE_DIR:Program1>)
