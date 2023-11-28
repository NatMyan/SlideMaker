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
                 {"-type", "-t", "-r", "-b", "-l", "-idx"}}, 
                 // {"-type", "-x", "-y", "-w", "-h", "-idx"}},
                {{"-lstyle", "-fcolour", "-lcolour", "-lwidth", "-down"}}},   // optional
        {"remove", {{"-id"},
                    {"-idx"}},
                   {{}}},                  // optional
        {"change", {{"-cidx", "-nidx"},
                    {"-id"}}, 
                   {{"-type", "-t", "-r", "-b", "-l"}}},      // optional
                    // {"-type", "-x", "-y", "-w", "-h"}      // optional
        {"display", {{"-id"},
                     {"-idx"},
                     {}},                  // mandatory empty
                    {{}}},                 // optional
        {"list", {{}}, {{}}},                   
        {"save", {{"-file"}}, {{}}},                    
        {"load", {{"-file"}}, {{}}},                    
        {"undo", {{}}, {{}}},
        {"redo", {{}}, {{}}},
        {"exit", {{}}, {{}}},
    }
{}

CommandNameType CommandRegistry::findCommandName (const std::string& cmdName) const {
    for (const auto& cmd : commandSpec_) {
        if (cmdName == cmd) {
            return cmd;
        }
    }
    throw Exception("Invalid command: " + cmdName);
}

CommandTemplateType CommandRegistry::getCommandTemplates() {
    return cmdTemplates_;
}

/*bool CommandRegistry::validateCommandArgNames(const CommandType& parsedCmd) const {
    CommandNameType cmd = "";
    try {
        cmd = findCommandName(parsedCmd.get<0>());
    }
    catch (const Exception&) {
        return false;
    }

    size_t ind = -1;
    for (size_t i = 0; i < cmdTemplates_.size(); ++i) {
        if (cmdTemplates_.at(i).commandName == cmd) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        return false;
    }

    std::vector<Key> parsedArgNames;
    for (const auto& pair : parsedCmd.get<1>()) {
        parsedArgNames.push_back(pair.first);
    }
    int matchingVecCount = 0;
    for (auto& mandatoryArgNames : cmdTemplates_.at(ind).mandatoryKeys) {
        if (std::includes(parsedArgNames.begin(), parsedArgNames.end(), mandatoryArgNames.begin(), mandatoryArgNames.end())) {
            ++matchingVecCount;
        }
    }
    if (matchingVecCount != 1) {
        return false;
    }
    for (auto& mandatoryArgNames : cmdTemplates_.at(ind).mandatoryKeys) {
        for (size_t i = 0; i < mandatoryArgNames.size(); ++i) {
            for (size_t j = 0; j < parsedArgNames.size(); ++j) {
                if (parsedArgNames.at(j) == mandatoryArgNames.at(i)) {
                    parsedArgNames.erase(parsedArgNames.begin() + j);
                }
            }
        }
    }

    matchingVecCount = 0;
    for (auto& optionalArgNames : cmdTemplates_.at(ind).mandatoryKeys) {
        if (std::includes(parsedArgNames.begin(), parsedArgNames.end(), optionalArgNames.begin(), optionalArgNames.end())) {
            ++matchingVecCount;
        }
    }
    if (matchingVecCount != 1) {
        return false;
    }
    for (auto& optionalArgNames : cmdTemplates_.at(ind).optionalKeys) {
        for (size_t i = 0; i < optionalArgNames.size(); ++i) {
            for (size_t j = 0; j < parsedArgNames.size(); ++j) {
                if (parsedArgNames.at(j) == optionalArgNames.at(i)) {
                    parsedArgNames.erase(parsedArgNames.begin() + j);
                }
            }
        }
    }
    if (!parsedArgNames.empty()) {
        return false;
    }

    return true;
}*/


/* 
    auto it = std::find_if(commandSpec_.begin(), commandSpec_.end(), [&parsedCmd](const std::string& spec) { 
        return spec == parsedCmd.get<0>(); 
    });

    if (it == commandSpec_.end()) {
        // std::cout << "Command not found in the registry: " << parsedCmd.get<0>() << std::endl;
        return false;
    }

    size_t index = std::distance(commandSpec_.begin(), it);
    const auto& templateArgs = cmdTemplates_[index];

    const auto& mandatoryArgs = templateArgs.mandatoryKeys;
    const auto& optionalArgs = templateArgs.optionalKeys;

    const auto& parsedArgs = parsedCmd.get<1>();

    // Check if all mandatory arguments are present
    if (!std::includes(parsedArgs.begin(), parsedArgs.end(), mandatoryArgs.begin(), mandatoryArgs.end())) {
        // std::cout << "Missing mandatory arguments for command: " << parsedCmd.get<0>() << std::endl;
        return false;
    }

    auto isArgValid = [&mandatoryArgs, &optionalArgs](const auto& arg) {
        bool hasMandatory = std::any_of(mandatoryArgs.begin(), mandatoryArgs.end(),
                                        [&arg](const auto& mandatoryVec) {
                                            return std::includes(arg.begin(), arg.end(), mandatoryVec.begin(), mandatoryVec.end());
                                        });
        return hasMandatory || std::find(optionalArgs.begin(), optionalArgs.end(), arg.first) != optionalArgs.end();
    };

    if (!std::all_of(parsedArgs.begin(), parsedArgs.end(), isArgValid)) {
        // std::cout << "Invalid arguments for command: " << parsedCmd.get<0>() << std::endl;
        return false;
    }

    // std::cout << "Command is valid: " << parsedCmd.first << std::endl;
    return true;
*/



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


