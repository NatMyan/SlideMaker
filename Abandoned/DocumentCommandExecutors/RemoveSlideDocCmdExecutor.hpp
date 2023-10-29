#ifndef REMOVE_SLIDE_COMMAND_EXECUTOR_HPP
#define REMOVE_SLIDE_COMMAND_EXECUTOR_HPP

#include "DocumentCommandExecutor.hpp"

class RemoveSlideDocCmdExecutor : public DocumentCommandExecutor {
    public:
        void execute (CommandType parsedCmd);
    
    private:
        bool isGivenSlideRange(std::map<std::string, ArgumentType> cmdPart);
        bool isGivenOneSlide(std::map<std::string, ArgumentType> cmdPart);
};

#endif // REMOVE_SLIDE_COMMAND_EXECUTOR_HPP