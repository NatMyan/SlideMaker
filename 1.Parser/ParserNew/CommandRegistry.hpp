#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "CommandStructure.hpp"

class CommandRegistry {
    public:
        CommandRegistry();
    
    public:    
        template <typename Operand>
        bool findCommandName (const std::string& commandName);

    private: 
        std::vector<std::string> commands;
        std::vector<std::string> combCommands;
};

#endif // COMMAND_REGISTRY_HPP