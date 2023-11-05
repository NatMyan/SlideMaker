#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include "Commands/Command.hpp"
#include "Commands/AddCommand.hpp"
#include "Commands/ChangeCommand.hpp"
#include "Commands/RemoveCommand.hpp"
#include "../Rendering/DisplayCommand.hpp"
#include "../Rendering/ListCommand.hpp"
#include "../Serializing/SaveCommand.hpp"
#include "../Serializing/LoadCommand.hpp"
// #include "Commands/ExitCommand.hpp"

class CommandFactory {
    public:
        static std::unique_ptr<Command> createCommand (const std::string& cmdName);
        ///TODO: static or not?
};

#endif // COMMAND_FACTORY_HPP