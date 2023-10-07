#ifndef EXIT_COMMAND_EXECUTOR_HPP
#define EXIT_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class ExitCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // EXIT_COMMAND_EXECUTOR_HPP