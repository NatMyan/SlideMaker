#ifndef PARSER_3_HPP
#define PARSER_3_HPP

#include "Command.hpp"
#include "CommandRegistry.hpp"

#include <string>
#include <utility>


class Parser3 {
    public:
        CommandUnderlyingType<double> parseCommand(std::string line);
};

/*
template <>
CommandUnderlyingType<double> Parser3<double>::parseCommand(const std::string& command);
*/
#endif // PARSER_3_HPP