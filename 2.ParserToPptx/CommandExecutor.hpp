#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Parser4.hpp"
#include "CommandValidator.hpp"

class CommandExecutor {
    public:
        virtual void execute (CommandType parsedCmd) = 0;

    protected:
        std::vector<std::variant<bool, std::map<std::string, ArgumentType> > > itemStorage_;
        static int index_;
};

int CommandExecutor::index_ = 0;

#endif // COMMAND_EXECUTOR_HPP