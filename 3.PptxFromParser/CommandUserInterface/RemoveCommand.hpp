#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "Command.hpp"

class RemoveCommand : public Command {
    public:
        void execute (CommandType parsedCmd);
};

#endif // REMOVE_COMMAND_HPP