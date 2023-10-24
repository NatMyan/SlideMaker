#ifndef LOAD_COMMAND_EXECUTOR_HPP
#define LOAD_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

using ItemType = std::tuple<ID, std::map<std::string, ArgumentType> >;

class LoadCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
    
    private:
        ItemType parseLineForLoad (std::string line);
        Shape createShapeFromIDAndAttributes(ID id, std::map<std::string, ArgumentType> attributes);
};

#endif // LOAD_COMMAND_EXECUTOR_HPP