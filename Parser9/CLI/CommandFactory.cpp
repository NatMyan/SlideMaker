#include "CommandFactory.hpp"
#include "Commands/AddCommand.hpp"
#include "Commands/ChangeCommand.hpp"
#include "Commands/RemoveCommand.hpp"
#include "Commands/DrawCommand.hpp"
#include "Commands/DisplayCommand.hpp"
#include "Commands/ListCommand.hpp"
#include "Commands/SaveCommand.hpp"
#include "Commands/LoadCommand.hpp"
#include "Commands/UndoCommand.hpp"
#include "Commands/RedoCommand.hpp"
#include "Commands/ExitCommand.hpp"

#include <iostream>

namespace cli {

std::unique_ptr<Command> CommandFactory::createCommand(const CommandInfo& cmdInfo) { 
    const auto cmdName = cmdInfo.first;
    const Map info = cmdInfo.second;
    
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
    else if (cmdName == "exit") return std::make_unique<ExitCommand>(info);
    else return nullptr;
}

}







