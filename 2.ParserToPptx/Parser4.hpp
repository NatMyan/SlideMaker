#ifndef PARSER_3_HPP
#define PARSER_4_HPP

// #include "Command.hpp"
#include "CommandRegistry.hpp"

#include <map>
#include <tuple>
#include <variant>

using ArgumentType = std::variant<std::string, int, double>;
using CommandType = std::tuple<int, CommandNameType, std::map<std::string, ArgumentType> >;
/// TODO: remove tuple[0] or not ???

class Parser4 {
    public:
        std::variant<CommandType, std::string> parseCommand(std::istream& input);
        
    private:
        ArgumentType parseArgumentValue(const std::string& argValue);
};

#endif // PARSER_4_HPP