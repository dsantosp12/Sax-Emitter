//
// Created by cisco on 12/9/17.
//

#ifndef SAX_EMITTER_TCPCONNECTION_HPP
#define SAX_EMITTER_TCPCONNECTION_HPP

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

#define SEND_DEFAULT_PORT 4028
#define SEND_DEFAULT_ADDR "127.0.0.1"

static const int BUFFER_SIZE = 1024;

using Socket = int;
using SocketLength = socklen_t;
using SocketAddress = struct sockaddr;
using SocketInputerAddress = struct sockaddr_in;


class TCPConnection {
public:
    explicit TCPConnection(int port, const char *address = nullptr);

    virtual ~TCPConnection();

    virtual void sendData(std::string data) = 0;
    virtual std::string receive() = 0;

protected:
    char* _buffer;
    const int _port;
    const char* _address;
    Socket _socket;
    Socket _clientSocket;
    SocketInputerAddress _server;
};


#endif //SAX_EMITTER_TCPCONNECTION_HPP
