cmake_minimum_required(VERSION 4.0)
project(PropCP VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(PropCP INTERFACE
        include/PropCP/handler.h
        include/PropCP/typelist.h
        include/PropCP/dispatch.h
        include/PropCP/propcp.h
)
target_include_directories(PropCP INTERFACE include)

option(BUILD_PROPCP_EXAMPLES "Build example applications" OFF)
if (BUILD_PROPCP_EXAMPLES)
    add_subdirectory(examples)
endif ()
