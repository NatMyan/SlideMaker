#include "Parser7.hpp"
#include "../CLI/CommandRegistry.hpp"
#include "../Exception.hpp"

#include <iostream>
#include <sstream>

CommandType Parser7::parseCommand(const std::string& input, const char& endOfLineToken) {
    MapPair<Key, Value> mapPair;
    std::istringstream iss(input);
    std::string endToken(1, endOfLineToken);
}