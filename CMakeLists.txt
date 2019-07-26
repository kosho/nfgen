cmake_minimum_required(VERSION 2.8)
project(netflow_traffic_generator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(nfgen main.cpp Worker.cpp Worker.h Timer.cpp Timer.h Options.cpp Options.h)