#ifndef DRAW_COMMAND_HPP
#define DRAW_COMMAND_HPP

#include "Command.hpp"

class DrawCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // DRAW_COMMAND_HPP