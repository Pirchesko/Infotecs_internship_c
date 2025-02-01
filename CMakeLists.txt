cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project ("Infotecs")

# Включите подпроекты.
add_subdirectory ("Library")
add_subdirectory ("Program1")
add_subdirectory ("Program2")
