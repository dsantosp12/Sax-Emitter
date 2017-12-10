#include <iostream>
#include <csignal>
#include <thread>
#include "TCPServerConnection.hpp"

#include "CGMinerAPI.hpp"

#define PORT_NUM 9430

int main() {
    auto server = new TCPServerConnection(PORT_NUM);

    auto cgminerConn = new CGMinerAPI();

    while(true) {
        std::string data = server->receive();

        auto jsonData = cgminerConn->sendCommand(data);

        server->sendData(jsonData.dump(2));
    }

    return 0;
}