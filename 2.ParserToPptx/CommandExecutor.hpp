#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Parser4.hpp"
#include "CommandValidator.hpp"

using ID = int;

class CommandExecutor {
    public:
        virtual void execute (CommandType parsedCmd) = 0;

    protected:
        // static std::vector<std::tuple<ID, std::variant<bool, std::map<std::string, ArgumentType> > > > itemStorage_;
        static std::vector<std::tuple<ID, std::map<std::string, ArgumentType> > > itemStorage_;
        static int index_;
};

int CommandExecutor::index_ = 0;

#endif // COMMAND_EXECUTOR_HPP