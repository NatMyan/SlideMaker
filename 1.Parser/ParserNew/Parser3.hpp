#ifndef PARSER_3_HPP
#define PARSER_3_HPP

#include "Command.hpp"
#include "CommandRegistry.hpp"

#include <string>

template <typename Operand>
class Parser3 {
    public:
        CommandUnderlyingType<Operand> parseCommand(std::string line);
};

#endif // PARSER_3_HPP