//
// Created by cisco on 12/10/17.
//

#include <arpa/inet.h>
#include <stdexcept>
#include <unistd.h>
#include "TCPClientConnection.hpp"

TCPClientConnection::TCPClientConnection(int port, const char *address) : TCPConnection(port, address) {}

TCPClientConnection::~TCPClientConnection() = default;

void TCPClientConnection::sendData(std::string data) {
    SocketInputerAddress destination;
    destination.sin_family = AF_INET;
    destination.sin_addr.s_addr = inet_addr(SEND_DEFAULT_ADDR);
    destination.sin_port = htons(SEND_DEFAULT_PORT);

    this->_clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    auto status = connect(this->_clientSocket, (SocketAddress*) &destination, sizeof(destination));

    if (status < 0 ){
        throw std::runtime_error("Connection failure while sending data.");
    }

    if (send(this->_clientSocket, data.c_str(), data.size(), 0) == -1) {
        throw std::runtime_error("Couldn't send data. Check client connection");
    }
}

std::string TCPClientConnection::receive() {
    auto numOfBytes = read(this->_clientSocket, this->_buffer, BUFFER_SIZE);

    if (numOfBytes == -1) {
        throw std::runtime_error("Error reading from the client socket.");
    }

    return this->_buffer;
}
