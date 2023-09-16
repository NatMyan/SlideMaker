#ifndef PARSER_3_HPP
#define PARSER_3_HPP

#include "FullCommand.hpp"

#include <string>

template <typename Operand>
class Parser3 {
    public:
        FullCommand<Operand> parseCommand(std::string line);
};

#endif // PARSER_3_HPP