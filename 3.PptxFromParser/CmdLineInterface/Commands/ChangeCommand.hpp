#ifndef CHANGE_COMMAND_HPP
#define CHANGE_COMMAND_HPP

#include "Command.hpp"

class ChangeCommand : public Command {
    public:
        void execute (CommandType parsedCmd);
};

#endif // CHANGE_COMMAND_HPP