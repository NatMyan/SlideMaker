#ifndef COMMAND_HPP
#define COMMAND_HPP

// #include "definitons.hpp"
#include "Tokenizer.hpp"

#include <string>
#include <map>
#include <vector>

template <typename Operand>
using CommandUnderlyingType = std::pair<std::string, std::map<std::string, std::vector<Operand>>>;

template <typename Operand>
class Command {
    public:
        CommandUnderlyingType<Operand> addArgument (const std::string& input);

};

#endif // COMMAND_HPP