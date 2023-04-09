cmake_minimum_required(VERSION 3.23)
project(15puzzle)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(googletest)