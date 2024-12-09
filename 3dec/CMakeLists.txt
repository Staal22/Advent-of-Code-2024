cmake_minimum_required(VERSION 3.30)
project(3dec)

set(CMAKE_CXX_STANDARD 20)

add_executable(3dec main.cpp
        instruction_parser.cpp
        instruction_parser.h)
