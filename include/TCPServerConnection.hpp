//
// Created by cisco on 12/10/17.
//

#ifndef SAX_EMITTER_TCPSERVERCONNECTION_HPP
#define SAX_EMITTER_TCPSERVERCONNECTION_HPP

#include "TCPConnection.hpp"

class TCPServerConnection : public TCPConnection {
public:
    explicit TCPServerConnection(int port, const char* address = nullptr);

    ~TCPServerConnection() override;

    void sendData(std::string data) override;

    std::string receive() override;
};


#endif //SAX_EMITTER_TCPSERVERCONNECTION_HPP
