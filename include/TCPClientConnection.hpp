//
// Created by cisco on 12/10/17.
//

#ifndef SAX_EMITTER_TCPCLIENTCONNECTION_HPP
#define SAX_EMITTER_TCPCLIENTCONNECTION_HPP


#include "TCPConnection.hpp"

class TCPClientConnection : public TCPConnection {
public:
    TCPClientConnection(int port, const char *address);

    ~TCPClientConnection() override;

    void sendData(std::string data) override;

    std::string receive() override;

};


#endif //SAX_EMITTER_TCPCLIENTCONNECTION_HPP
