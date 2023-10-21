#ifndef ADD_SLIDE_COMMAND_EXECUTOR_HPP
#define ADD_SLIDE_COMMAND_EXECUTOR_HPP

#include "DocumentCommandExecutor.hpp"

class AddSlideDocCmdExecutor : public DocumentCommandExecutor {
    public:
        void execute (CommandType parsedCmd);
};

#endif // ADD_SLIDE_COMMAND_EXECUTOR_HPP