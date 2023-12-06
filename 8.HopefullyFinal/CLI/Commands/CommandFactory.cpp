#include "CommandFactory.hpp"

std::unique_ptr<Command> CommandFactory::createCommand (const CommandInfo& cmdInfo) { 
    if (cmdInfo.first == "add") return std::make_unique<AddCommand>(cmdInfo.second);
    else if (cmdInfo.first == "change") return std::make_unique<ChangeCommand>(cmdInfo.second);
    else if (cmdInfo.first == "remove") return std::make_unique<RemoveCommand>(cmdInfo.second);
    else if (cmdInfo.first == "display") return std::make_unique<DisplayCommand>(cmdInfo.second);
    else if (cmdInfo.first == "list") return std::make_unique<ListCommand>(cmdInfo.second);
    else if (cmdInfo.first == "draw") return std::make_unique<DrawCommand>(cmdInfo.second);
    else if (cmdInfo.first == "undo") return std::make_unique<UndoCommand>(cmdInfo.second);
    else if (cmdInfo.first == "redo") return std::make_unique<RedoCommand>(cmdInfo.second);
    else if (cmdInfo.first == "save") return std::make_unique<SaveCommand>(cmdInfo.second);
    else if (cmdInfo.first == "load") return std::make_unique<LoadCommand>(cmdInfo.second);
    // else if (cmdInfo.first == "exit") return std::make_unique<ExitCommand>();
    else return nullptr;
}


/*
#include <functional>
#include <memory>
#include <string>

std::unique_ptr<Command> CommandFactory::createCommand(const std::string& cmdName) {
    static const std::unordered_map<std::string, std::function<std::unique_ptr<Command>()> > commandMap = {
        {"add", [] { return std::make_unique<AddCommand>(); }},
        {"change", [] { return std::make_unique<ChangeCommand>(); }},
        {"remove", [] { return std::make_unique<RemoveCommand>(); }},
        {"display", [] { return std::make_unique<DisplayCommand>(); }},
        {"list", [] { return std::make_unique<ListCommand>(); }},
        {"undo", [] { return std::make_unique<UndoCommand>(); }},
        {"redo", [] { return std::make_unique<RedoCommand>(); }},
        {"save", [] { return std::make_unique<SaveCommand>(); }},
        {"load", [] { return std::make_unique<LoadCommand>(); }},
    };
    auto it = commandMap.find(cmdName); 
    return (it != commandMap.end()) ? it->second() : nullptr;
}
*/
