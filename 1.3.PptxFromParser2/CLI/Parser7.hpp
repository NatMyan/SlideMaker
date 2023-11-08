#ifndef PARSER_7_HPP
#define PARSER_7_HPP

#include "../definitions.hpp"

class Parser7 {
    public:
        CommandType parseCommand (const std::string& input, const char& endOfLineToken);
};

#endif // PARSER_7_HPP