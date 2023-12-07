#ifndef COMMAND_FACTORYY_HPP
#define COMMAND_FACTORYY_HPP

#include "Commands/Command.hpp"
#include "Commands/AddCommand.hpp"
#include "Commands/ChangeCommand.hpp"
#include "Commands/RemoveCommand.hpp"
#include "Commands/DisplayCommand.hpp"
#include "Commands/ListCommand.hpp"
#include "Commands/SaveCommand.hpp"
#include "Commands/LoadCommand.hpp"
#include "Commands/UndoCommand.hpp"
#include "Commands/RedoCommand.hpp"
// #include "Commands/ExitCommand.hpp"
#include "../../definitions.hpp"

#include <functional>
#include <memory>
#include <string>

class CommandFactory {
    public:
        CommandFactory(const CommandInfo& cmdInfo);
        std::unique_ptr<Command> createCommand();
    
    private:
        CommandInfo cmdInfo_;
        // std::unordered_map<std::string, std::function<std::unique_ptr<Command>(Map)> > commandMap_;
};

#endif // COMMAND_FACTORYY_HPP