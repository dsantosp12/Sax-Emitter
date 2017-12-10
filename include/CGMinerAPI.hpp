//
// Created by cisco on 12/9/17.
//

#ifndef SAX_EMITTER_CGMINERAPI_HPP
#define SAX_EMITTER_CGMINERAPI_HPP

#include <string>

#include "json.hpp"
#include "TCPConnection.hpp"

using namespace nlohmann;

class CGMinerAPI {
public:
    CGMinerAPI();

    json sendCommand(std::string command);

private:
    TCPConnection* _connection;
};


#endif //SAX_EMITTER_CGMINERAPI_HPP
