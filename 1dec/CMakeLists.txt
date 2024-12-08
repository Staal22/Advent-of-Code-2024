cmake_minimum_required(VERSION 3.30)
project(1dec)

set(CMAKE_CXX_STANDARD 20)

add_executable(1dec main.cpp
        list_parser.cpp
        list_parser.h)
