#include "CommandExecutorFactory.hpp"

#include <iostream>

std::unique_ptr<CommandExecutor> CommandExecutorFactory::createCommandExecutor (const std::string& cmdName) { // (const CommandType& parsedCmd) {
    /*auto cmdName = std::get<0>(parsedCmd);
    auto typeName = std::get<1>(parsedCmd);//(std::get<1>(parsedCmd))["-type"]);
    auto tpnm = convertToString(typeName["-type"]);*/
    if (cmdName == "add") {
        return std::make_unique<AddCommandExecutor>();
    }
    else if (cmdName == "change") {
        return std::make_unique<ChangeCommandExecutor>();
    }
    else if (cmdName == "remove") {
        return std::make_unique<RemoveCommandExecutor>();
    }
    else if (cmdName == "display") {
        return std::make_unique<DisplayCommandExecutor>();
    }
    else if (cmdName == "list") {
        return std::make_unique<ListCommandExecutor>();
    }
    else if (cmdName == "exit") {
        return std::make_unique<ExitCommandExecutor>();
    }
    else if (cmdName == "save") {
        return std::make_unique<SaveCommandExecutor>();
    }
    else if (cmdName == "load") {
        return std::make_unique<LoadCommandExecutor>();
    }
    else {
        return nullptr;
    }
}

std::string CommandExecutorFactory::convertToString (ArgumentType arg) {
    struct {
        std::string operator()(const std::string& str) const {
            return str;
        }
        std::string operator()(const int& value) const {
            return std::to_string(value);
        }
        std::string operator()(const double value) const {
            return std::to_string(value);
        }
    } visitor;

    return std::visit(visitor, arg);
}