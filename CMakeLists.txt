cmake_minimum_required(VERSION 3.22)
project(HawkSignalingServer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Drogon REQUIRED)
find_package(jsoncpp REQUIRED)

add_subdirectory(src/Hawk)