#include "CommandFactory.hpp"

std::unique_ptr<Command> CommandFactory::createCommand (const std::string& cmdName) { 
    if (cmdName == "add") return std::make_unique<AddCommand>();
    else if (cmdName == "change") return std::make_unique<ChangeCommand>();
    else if (cmdName == "remove") return std::make_unique<RemoveCommand>();
    else if (cmdName == "display") return std::make_unique<DisplayCommand>();
    else if (cmdName == "list") return std::make_unique<ListCommand>();
    else if (cmdName == "undo") return std::make_unique<UndoCommand>();
    else if (cmdName == "redo") return std::make_unique<RedoCommand>();
    else if (cmdName == "save") return std::make_unique<SaveCommand>();
    else if (cmdName == "load") return std::make_unique<LoadCommand>();
    // else if (cmdName == "exit") return std::make_unique<ExitCommand>();
    else return nullptr;
}

/*std::unique_ptr<Command> CommandFactory::createCommand(const std::string& cmdName) {
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
}*/


