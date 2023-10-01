#include "CommandRegistry.hpp"

CommandRegistry::CommandRegistry () : 
    commandSpec_ {
        "add", "remove", "change", "display", 
        "list", "exit", "save", "load"
    }
{}

CommandNameType CommandRegistry::findCommand (const std::string& commandName) {
    std::string wrongCommandErrorMsg = "wrong_command";
    for (const auto& cmd : commandSpec_) 
        if (commandName == cmd) 
            return cmd;
    return wrongCommandErrorMsg;
}


    