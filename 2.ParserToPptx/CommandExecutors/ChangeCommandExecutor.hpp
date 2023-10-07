#ifndef CHANGE_COMMAND_EXECUTOR_HPP
#define CHANGE_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class ChangeCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // CHANGE_COMMAND_EXECUTOR_HPP