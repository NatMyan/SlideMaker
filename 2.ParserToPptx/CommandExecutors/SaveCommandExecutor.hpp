#ifndef SAVE_COMMAND_EXECUTOR_HPP
#define SAVE_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class SaveCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
    
    private:
        std::string convertToString (ArgumentType arg);
};

#endif // SAVE_COMMAND_EXECUTOR_HPP