#include "CommandRegistry.hpp"
#include "../Exception.hpp"

#include <algorithm>

CommandRegistry::CommandRegistry () :
    commandSpec_ {
        "add", "remove", "change", "display", 
        "list", "exit", "save", "load", 
        "undo", "redo"
    },
    cmdTemplates_ {
        {"add", {{"-type"}, 
                 {"-type", "-t", "-r", "-b", "-l", "-idx"}, 
                 {"-type", "-x", "-y", "-w", "-h", "-idx"}}},
        {"remove", {{"-id"},
                    {"-idx"}}},
        {"change", {{"-cidx", "-nidx"},
                    {"-id", "-type", "-t", "-r", "-b", "-l"}, // contains one of these or some of these
                    {"-id", "-x", "-y", "-w", "-h"}}}, // contains one of these or some of these
        {"display", {{"-id"},
                     {}}},
        {"list", {{}}},
        {"save", {{"-file"}}},
        {"load", {{"-file"}}},
        {"undo", {{}}},
        {"redo", {{}}},
        {"exit", {{}}},
    }
{}

CommandNameType CommandRegistry::findCommandName (const std::string& cmdName) {
    for (const auto& cmd : commandSpec_) {
        if (cmdName == cmd) {
            return cmd;
        }
    }
    throw Exception("Invalid command: " + cmdName);
}

CommandTemplateType CommandRegistry::getCommandTemplate() {
    return cmdTemplates_;
}

/*CommandTemplateType CommandRegistry::findCommand (const std::string& cmdName, const MapPair<Key, Value> args) {
    for (const auto& command : cmdTemplates_) {
        if (cmdName == command.commandName) {
            for (const auto& arg : args) {
                if (std::binary_search(command.possibleKeys.begin(), command.possibleKeys.end(), "-id") 
                    && std::binary_search(command.possibleKeys.begin(), command.possibleKeys.end(), arg.first)) {
                    
                }
            }
        }
    }
}*/


