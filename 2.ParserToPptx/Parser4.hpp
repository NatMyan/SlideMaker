#ifndef PARSER_4_HPP
#define PARSER_4_HPP

#include "definitions.hpp"
#include "CommandRegistry.hpp"

class Parser4 {
    public:
        // std::variant<CommandType, std::string> parseCommand(std::string input, const char& endOfLineToken);
        CommandType parseCommand(std::string input, const char& endOfLineToken);
        
    private:
        ArgumentType parseArgumentValue(const std::string& argValue);
};

#endif // PARSER_4_HPP