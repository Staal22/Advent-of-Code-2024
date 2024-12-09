cmake_minimum_required(VERSION 3.30)
project(4dec)

set(CMAKE_CXX_STANDARD 20)

add_executable(4dec main.cpp
        puzzle_parser.cpp
        puzzle_parser.h)
