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

CommandTemplateType CommandRegistry::findCommand (const std::string& cmdName, const MapPair<Key, Value> args) {
    for (const auto& command : cmdTemplates_) {
        if (cmdName == command.commandName) {
            for (const auto& arg : args) {
                if (std::binary_search(command.possibleKeys.begin(), command.possibleKeys.end(), "-id") 
                    && std::binary_search(command.possibleKeys.begin(), command.possibleKeys.end(), arg.first)) {
                    
                }
            }
        }
    }
}

/*
bool matchesCommandTemplate(const CommandType& parsedCmd, const CommandTemplate& template) {
    // Check if the command name matches.
    if (parsedCmd.get<0>() == template.commandName) {
        const auto& parsedKeys = parsedCmd.get<1>();
        for (const auto& possibleKeys : template.possibleKeys) {
            // Check if the parsed keys match one of the possible key combinations.
            if (parsedKeys.size() == possibleKeys.size()) {
                bool keysMatch = true;
                for (const auto& key : possibleKeys) {
                    if (parsedKeys.find(key) == parsedKeys.end()) {
                        keysMatch = false;
                        break;
                    }
                }
                if (keysMatch) {
                    return true; // Parsed command matches this template.
                }
            }
        }
    }
    return false; // Parsed command doesn't match this template.
}
*/   