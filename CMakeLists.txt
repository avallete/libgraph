cmake_minimum_required(VERSION 3.7)
project(libgraph)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(libgraph ${SOURCE_FILES})