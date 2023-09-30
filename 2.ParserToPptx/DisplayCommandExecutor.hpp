#ifndef DISPLAY_COMMAND_EXECUTOR_HPP
#define DISPLAY_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class DisplayCommandExecutor : public CommandExecutor {
    public:
        void execute (CommandType parsedCmd);
    
    private:
        std::string convertToString (ArgumentType arg);
};

#endif // DISPLAY_COMMAND_EXECUTOR_HPP