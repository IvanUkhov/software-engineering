cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(interview)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)
