#include "CommandRegistry.hpp"
#include "../Exception.hpp"

CommandRegistry::CommandRegistry () : 
    commandSpec_ {
        "add", "remove", "change", "display", 
        "list", "exit", "save", "load"
    }
{}

CommandNameType CommandRegistry::findCommand (const std::string& commandName) {
    for (const auto& cmd : commandSpec_) {
        if (commandName == cmd) {
            return cmd;
        }
    }
    throw Exception("Invalid command: " + commandName);
}


    