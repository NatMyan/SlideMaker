#include "CommandExecutorFactory.hpp"

#include <iostream>

std::unique_ptr<CommandExecutor> CommandExecutorFactory::createCommandExecutor (const std::string& cmdName) {
    if (cmdName == "add") {
        std::cout << "adding" << std::endl;
        return std::make_unique<AddCommandExecutor>();
    }
    /*else if (cmdName == "change") {
        return std::make_unique<ChangeCommandExecutor>();
    }*/
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