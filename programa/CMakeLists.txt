cmake_minimum_required(VERSION 3.10)
project(teksto_apdorojimas)
include_directories(Include)
file(GLOB SOURCES "src/*.cpp")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(teksto_apdorojimas ${SOURCES})