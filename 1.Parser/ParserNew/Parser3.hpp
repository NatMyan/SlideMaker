#ifndef PARSER_3_HPP
#define PARSER_3_HPP

#include "CommandStructure.hpp"
#include "CommandRegistry.hpp"

#include <string>

template <typename Operand>
class Parser3 {
    public:
        CommandStructureUnderlyingType<Operand> parseCommand(std::string line);
};

#endif // PARSER_3_HPP