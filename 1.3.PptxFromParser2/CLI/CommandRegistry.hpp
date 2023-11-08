#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "../definitions.hpp"
#include "Tokenizer.hpp"

class CommandRegistry {
    public:
        CommandRegistry();
        
    public:
        CommandNameType findCommandName (const std::string& cmdName); // commandName is from takeToken
        CommandTemplateType getCommandTemplate();
        // CommandTemplateType findCommand (const std::string& cmdName, const MapPair<Key, Value> args); 

    private:
        std::vector<CommandNameType> commandSpec_;
        CommandTemplateType cmdTemplates_;
};

#endif // COMMAND_REGISTRY_HPP