#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Parser3.hpp"
#include "CommandValidator.hpp"

class CommandExecutor {
    public:
        double executeCommand (CommandUnderlyingType<double> parsedCmd);
};

#endif // COMMAND_EXECUTOR_HPP