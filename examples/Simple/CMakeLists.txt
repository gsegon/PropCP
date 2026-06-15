cmake_minimum_required(VERSION 3.12)
project(TagDispatchExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TagDispatchExample
        main.cpp
        custom.h
        framework.h
)
