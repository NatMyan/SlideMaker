#ifndef DISPLAY_COMMAND_EXECUTOR_HPP
#define DISPLAY_COMMAND_EXECUTOR_HPP

#include "RendererCommand.hpp"

class DisplayCommand : public RendererCommand {
    public:
        void execute (CommandType parsedCmd);
};

#endif // DISPLAY_COMMAND_EXECUTOR_HPP