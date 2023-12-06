#include "CommandFactory.hpp"

CommandFactory::CommandFactory(const CommandInfo& cmdInfo) :
    cmdInfo_(cmdInfo)
{}

std::unique_ptr<Command> CommandFactory::createCommand() { 
    const auto cmdName = cmdInfo_.first;
    const Map info = cmdInfo_.second;
    if (cmdName == "add") return std::make_unique<AddCommand>(info);
    else if (cmdName == "change") return std::make_unique<ChangeCommand>(info);
    else if (cmdName == "remove") return std::make_unique<RemoveCommand>(info);
    else if (cmdName == "display") return std::make_unique<DisplayCommand>(info);
    else if (cmdName == "list") return std::make_unique<ListCommand>(info);
    else if (cmdName == "draw") return std::make_unique<DrawCommand>(info);
    else if (cmdName == "undo") return std::make_unique<UndoCommand>(info);
    else if (cmdName == "redo") return std::make_unique<RedoCommand>(info);
    else if (cmdName == "save") return std::make_unique<SaveCommand>(info);
    else if (cmdName == "load") return std::make_unique<LoadCommand>(info);
    // else if (cmdName == "exit") return std::make_unique<ExitCommand>();
    else return nullptr;
}


/*CommandFactory::CommandFactory(const CommandInfo& cmdInfo) :
    cmdInfo_(cmdInfo)
{
    const Map info = cmdInfo.second;
    commandMap_ = {
        {"add", [info] { return std::make_unique<AddCommand>(info); }},
        {"change", [info] { return std::make_unique<ChangeCommand>(info); }},
        {"remove", [info] { return std::make_unique<RemoveCommand>(info); }},
        {"display", [info] { return std::make_unique<DisplayCommand>(info); }},
        {"list", [info] { return std::make_unique<ListCommand>(info); }},
        {"undo", [info] { return std::make_unique<UndoCommand>(info); }},
        {"redo", [info] { return std::make_unique<RedoCommand>(info); }},
        {"save", [info] { return std::make_unique<SaveCommand>(info); }},
        {"load", [info] { return std::make_unique<LoadCommand>(info); }}
    };
}

std::unique_ptr<Command> CommandFactory::createCommand() {
    auto it = commandMap_.find(cmdInfo_.first); 
    return (it != commandMap_.end()) ? it->second() : nullptr;
}*/







