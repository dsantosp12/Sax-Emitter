//
// Created by cisco on 12/9/17.
//

#include <TCPClientConnection.hpp>
#include "CGMinerAPI.hpp"


CGMinerAPI::CGMinerAPI() : _connection(nullptr) {
}

json CGMinerAPI::sendCommand(std::string command) {
    this->_connection = new TCPClientConnection(4028, "localhost");

    json payload;
    payload["command"] = command;

    this->_connection->sendData(payload.dump());

    auto data = this->_connection->receive();

    delete this->_connection;

    return  payload;
}
