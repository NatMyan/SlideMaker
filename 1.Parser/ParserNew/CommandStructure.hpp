#ifndef COMMAND_HPP
#define COMMAND_HPP

// #include "definitons.hpp"

#include <string>
#include <unordered_map>
#include <vector>

template <typename Operand>
using CommandStructureUnderlyingType = std::pair<std::string, std::vector<std::unordered_map<std::string, Operand>>>;

template <typename Operand>
class CommandStructure {
    public:
        CommandStructureUnderlyingType<Operand> addArgument(std::string line);

    private:
        std::vector<std::unordered_map<std::string, Operand>> commandStructure;
};

#endif // COMMAND_HPP