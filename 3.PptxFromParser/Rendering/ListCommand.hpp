#ifndef LIST_COMMAND_EXECUTOR_HPP
#define LIST_COMMAND_EXECUTOR_HPP

#include "RendererCommand.hpp"

class ListCommand : public RendererCommand {
    public:
        void execute (CommandType parsedCmd);
};

#endif // LIST_COMMAND_EXECUTOR_HPP