#ifndef RENDERER_COMMAND_HPP
#define RENDERER_COMMAND_HPP

#include "../CmdLineInterface/Commands/Command.hpp"

class RendererCommand : public Command {
    public:
        virtual void execute(CommandType parsedCmd) = 0;
};

#endif // RENDERER_COMMAND_HPP