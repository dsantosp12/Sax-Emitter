cmake_minimum_required(VERSION 3.9)
project(sax_emitter)

set(CMAKE_CXX_STANDARD 11)

link_libraries(pthread)

include_directories("include")

add_executable(sax_emitter main.cpp src/CGMinerAPI.cpp include/CGMinerAPI.hpp src/TCPConnection.cpp include/TCPConnection.hpp src/TCPClientConnection.cpp include/TCPClientConnection.hpp src/TCPServerConnection.cpp include/TCPServerConnection.hpp)
