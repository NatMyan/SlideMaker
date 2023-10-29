#ifndef EXIT_COMMAND_EXECUTOR_HPP
#define EXIT_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class ExitCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
        bool getExitVal();

    private:
        bool isExit_ = false;
};

#endif // EXIT_COMMAND_EXECUTOR_HPP