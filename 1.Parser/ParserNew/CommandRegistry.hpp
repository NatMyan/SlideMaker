#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "Command.hpp"

class CommandRegistry {
    public:
        CommandRegistry();
    
    public:    
        bool findCommand (const std::string& commandName);

    private: 
        std::vector<CommandUnderlyingType<double>> instantCmds;
        std::vector<CommandUnderlyingType<double>> conserverCmds;
};

#endif // COMMAND_REGISTRY_HPP