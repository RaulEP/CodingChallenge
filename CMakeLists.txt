cmake_minimum_required(VERSION 3.9.1)

project(ATMController)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

set(SOURCES src/main.cpp 
            src/ATMController.cpp)

add_executable(atm_controller ${SOURCES})