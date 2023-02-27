cmake_minimum_required(VERSION 3.20)
project(CMAKE_DEMO)

include_directories(include)

set (SRC
./src/main.cpp
)

add_executable(app ${SRC})
