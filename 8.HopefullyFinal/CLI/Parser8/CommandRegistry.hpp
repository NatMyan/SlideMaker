#ifndef COMMAND_REGISTRYY_HPP
#define COMMAND_REGISTRYY_HPP

#include "../../definitions.hpp"

class CommandRegistry {
    public:
        CommandRegistry();
        
    public:
        std::string findCommandName (const std::string& cmdName) const; // commandName is from takeToken
        std::vector<CommandTemplate>::iterator findCmdIter(const std::string& cmdName);
        std::vector<CommandTemplate> getCommandTemplates();
        
    private:
        std::vector<CommandTemplate> cmdTemplates_;
        // std::vector<std::string> commandSpec_;
};

#endif // COMMAND_REGISTRYY_HPP