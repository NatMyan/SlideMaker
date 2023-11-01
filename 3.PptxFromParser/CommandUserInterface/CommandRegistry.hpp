#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "../definitions.hpp"
#include "Tokenizer.hpp"

class CommandRegistry {
    public:
        CommandRegistry ();
        
    public:
        CommandNameType findCommand (const std::string& commandName); // commandName is from takeToken

    private:
        std::vector<CommandNameType> commandSpec_;
};

#endif // COMMAND_REGISTRY_HPP