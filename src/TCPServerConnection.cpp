//
// Created by cisco on 12/10/17.
//

#include <stdexcept>
#include <arpa/inet.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <strings.h>
#include "TCPServerConnection.hpp"

TCPServerConnection::TCPServerConnection(int port, const char *address) : TCPConnection(port, address) {
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (this->_socket < 0) {
        throw std::runtime_error("Socket wasn't allocated correctly");
    }

    // The all bytes to zero
    bzero((char*) &this->_server, sizeof(this->_server));

    this->_server.sin_family = AF_INET;

    if (address) {
        this->_server.sin_addr.s_addr = inet_addr(address);
    } else {
        this->_server.sin_addr.s_addr = INADDR_ANY;
    }

    this->_server.sin_port = htons(this->_port);

    if (bind(this->_socket, (SocketAddress *) &this->_server, sizeof(this->_server)) < 0) {
        throw std::runtime_error("Socket couldn't be bind with server address ");
    }

    listen(this->_socket, 5);

    char humanAddr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &this->_server.sin_addr, humanAddr, INET_ADDRSTRLEN);

    std::cout << "Server listening on tcp://" << humanAddr << ":" << this->_port << std::endl;
}

TCPServerConnection::~TCPServerConnection() = default;

void TCPServerConnection::sendData(std::string data) {
    if (send(this->_clientSocket, data.c_str(), data.size(), 0) == -1) {
        throw std::runtime_error("Couldn't send data. Check client connection");
    }
}

std::string TCPServerConnection::receive() {
    SocketInputerAddress userAddress;
    SocketLength clientAddrLength = sizeof(userAddress);

    this->_clientSocket = accept(this->_socket, (SocketAddress*) &userAddress, &clientAddrLength);

    if (this->_clientSocket < 0) {
        throw std::runtime_error("Accepted connection with error");
    }

    char humaAddress[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &userAddress.sin_addr, humaAddress, INET_ADDRSTRLEN);
    std::cout << "Connection received from " << humaAddress << ":" << userAddress.sin_port << std::endl;


    auto numOfBytes = read(this->_clientSocket, this->_buffer, BUFFER_SIZE);

    if (numOfBytes == -1) {
        throw std::runtime_error("Error reading from the socket.");
    }

    return this->_buffer;
}
