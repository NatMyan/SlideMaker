#include "CommandRegistry.hpp"

CommandRegistry::CommandRegistry () :
    commands {  
        "add", "sub", "mul", "div", "mod", "pow", "sqr",
        "and", "nand", "or", "nor", "xor", "xnor", "not",
        "clear", "run"
    },
    combCommands {
        "create"
    } 
{}

template <typename Operand>
bool CommandRegistry::findCommandName (const std::string& commandName) {
    std::string commandPart = commandName;

    for (const auto& combCommand : combCommands) {
        auto startIndex = commandPart.find(combCommand);
        if (startIndex != std::string::npos) {
            startIndex += combCommand.size();
            commandPart = commandPart.substr(startIndex);
            break;
        }
    }

    auto endIndex = commandPart.find("-"); // first dash
    if (endIndex != std::string::npos) {
        commandPart = commandPart.substr(0, endIndex); // before dash
    }

    for (const auto& cmd : commands) {
        auto startIndex = commandPart.find(cmd);
        if (startIndex != std::string::npos) {
            startIndex += cmd.size();
            commandPart = commandPart.substr(startIndex);
            break;
        }
    }

    if (commandPart == " ") {
        commandPart.clear();
    }

    return commandPart.empty();
}


    /*std::string commandPart = commandName;

    for (auto i = 0; i < combCommands.size(); ++i) {
        if (commandPart.find(combCommands.at(i)) != std::string::npos) {
            auto startIndex = combCommands.at(i).size() + 1;
            commandPart = commandPart.substr(startIndex, commandPart.size() - startIndex);
            break;
        }
    }

    auto endIndex = commandPart.find("-") - 1;
    commandPart = commandPart.substr(0, endIndex);

    for (auto i = 0; i < commands.size(); ++i) {
        if (commandPart.find(commands.at(i)) != std::string::npos) {
            auto startIndex = commands.at(i).size() + 1;
            commandPart = commandPart.substr(startIndex, commandPart.size() - startIndex);
            break;
        }
    }*/