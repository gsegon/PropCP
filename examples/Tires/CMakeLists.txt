cmake_minimum_required(VERSION 3.12)
add_executable(Tires main.cpp
        ExternalTypes.h
        Properties.h

)
target_include_directories(Tires PRIVATE include)
target_link_libraries(Tires PRIVATE PropCP)