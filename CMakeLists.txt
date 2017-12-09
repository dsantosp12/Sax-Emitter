cmake_minimum_required(VERSION 3.9)
project(sax_emitter)

set(CMAKE_CXX_STANDARD 11)

include_directories("include")

add_executable(sax_emitter main.cpp)