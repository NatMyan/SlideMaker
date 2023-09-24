#ifndef ADD_COMMAND_EXECUTOR_HPP
#define ADD_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class AddCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // ADD_COMMAND_EXECUTOR_HPP