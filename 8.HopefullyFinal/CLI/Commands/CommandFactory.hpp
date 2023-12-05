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

class CommandFactory {
    public:
        static std::unique_ptr<Command> createCommand (const std::string& cmdName);
        ///TODO: static or not?
};

#endif // COMMAND_FACTORYY_HPP