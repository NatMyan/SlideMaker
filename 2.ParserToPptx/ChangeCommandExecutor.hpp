#ifndef CHANGE_COMMAND_EXECUTOR_HPP
#define CHANGE_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class ChangeCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
    private:
        void changeCommand();
};

#endif // CHANGE_COMMAND_EXECUTOR_HPP