#ifndef COMMAND_HPP
#define COMMAND_HPP

// #include "definitons.hpp"
#include "Tokenizer.hpp"

#include <string>
#include <map>
#include <vector>

template <typename Operand>
using CommandStructureUnderlyingType = std::pair<std::string, std::map<std::string, std::vector<Operand>>>;

template <typename Operand>
class CommandStructure {
    public:
        CommandStructureUnderlyingType<Operand> rebuldCommand (const std::string& input);

    /*private:
        std::vector<std::map<std::string, Operand>> commandStructure;*/
};

#endif // COMMAND_HPP