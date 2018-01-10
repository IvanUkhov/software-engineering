cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(playground)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)
