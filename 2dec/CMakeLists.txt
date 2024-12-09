cmake_minimum_required(VERSION 3.30)
project(2dec)

set(CMAKE_CXX_STANDARD 20)

add_executable(2dec main.cpp
        report_parser.cpp
        report_parser.h)
