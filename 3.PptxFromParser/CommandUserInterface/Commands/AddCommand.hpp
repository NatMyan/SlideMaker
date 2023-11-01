#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "Command.hpp"

class AddCommand : public Command {
    public:
        void execute (CommandType parsedCmd);
};

#endif // ADD_COMMAND_HPP