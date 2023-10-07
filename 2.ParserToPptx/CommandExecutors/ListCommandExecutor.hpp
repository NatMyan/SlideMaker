#ifndef LIST_COMMAND_EXECUTOR_HPP
#define LIST_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class ListCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // LIST_COMMAND_EXECUTOR_HPP