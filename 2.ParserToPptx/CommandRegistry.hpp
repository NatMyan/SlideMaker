#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "Tokenizer.hpp"

using CommandNameType = std::string;

class CommandRegistry {
    public:
        CommandRegistry ();
        
    public:
        CommandNameType findCommand (const std::string& commandName); // commandName is from getToken

    private:
        std::vector<CommandNameType> commandSpec_;
};

#endif // COMMAND_REGISTRY_HPP