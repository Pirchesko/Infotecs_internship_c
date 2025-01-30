cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project ("Infotecs")

# Включите подпроекты.
add_subdirectory ("Library")
add_subdirectory ("Program1")
