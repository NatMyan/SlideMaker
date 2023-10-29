#ifndef REMOVE_COMMAND_EXECUTOR_HPP
#define REMOVE_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class RemoveCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // REMOVE_COMMAND_EXECUTOR_HPP