#ifndef PARSER_6_HPP
#define PARSER_6_HPP

#include "../definitions.hpp"

class Parser6 {
    public:
        CommandType parseCommand(std::string input, const char& endOfLineToken);
};

#endif // PARSER_6_HPP