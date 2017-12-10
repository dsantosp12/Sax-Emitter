//
// Created by cisco on 12/9/17.
//

#include <unistd.h>

#include "TCPConnection.hpp"

TCPConnection::TCPConnection(int port, const char *address) : _port(port), _address(address),
                                                              _buffer(new char [BUFFER_SIZE]) { }

TCPConnection::~TCPConnection() {
    close(this->_socket);
    close(this->_clientSocket);
}
