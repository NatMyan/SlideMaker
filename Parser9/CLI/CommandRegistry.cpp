#include "CommandRegistry.hpp"
#include "../../Exception.hpp"

#include <algorithm>

namespace cli {

CommandRegistry::CommandRegistry () :
    cmdTemplates_ {
        {"add", {{"-type"}, 
                 {"-type", "-t", "-r", "-b", "-l", "-idx"}}, 
                {{"-lstyle", "-fcolour", "-lcolour", "-lwidth", "-angle", "-sideCount", "-text", "-tcolour", "-tsize"}}},   // optional
        {"remove", {{"-id"},
                    {"-idx"}},
                   {{}}},                  // optional
        {"change", {{"-id"}}, 
                   {{"-t", "-r", "-b", "-l", "-lstyle", "-fcolour", "-lcolour", "-lwidth", "-angle", "-sideCount", "-text"}}},  // optional
        {"move",   {{"-cidx", "-nidx"}}, {{}}},
        // {"switch", {{"-idx"}}},
        {"display", {{"-id"},
                     {"-idx"},
                     {}},                  // mandatory empty
                    {{}}},                 // optional
        {"draw", {{"-idx", "-file"}}, 
                 {{}}},
        {"list", {{}}, {{}}},                   
        {"save", {{"-file"}}, {{}}},                    
        {"load", {{"-file"}}, {{}}},                    
        {"undo", {{}}, {{}}},
        {"redo", {{}}, {{}}},
        {"exit", {{}}, {{}}},
    }
{}

std::string CommandRegistry::findCommandName (const std::string& cmdName) const {
    for (auto cmd : cmdTemplates_) {
        if (cmd.commandName == cmdName) {
            return cmd.commandName;
        }
    }
    throw InvalidCommandNameException ("Command name not found: " + cmdName);
}

std::vector<CommandTemplate>::iterator CommandRegistry::findCmdIter(const std::string& cmdName) {
    for (auto iter = cmdTemplates_.begin(); iter != cmdTemplates_.end(); ++iter) {
        if (iter->commandName == cmdName) {
            return iter;
        }
    }
    // throw InvalidCommandNameException ("Command name iterator not found: " + cmdName); 
}

std::vector<CommandTemplate> CommandRegistry::getCommandTemplates() {
    return cmdTemplates_;
}

}



