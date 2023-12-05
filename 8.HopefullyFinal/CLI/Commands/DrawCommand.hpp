#ifndef DRAW_COMMANDD_HPP
#define DRAW_COMMANDD_HPP

#include "Command.hpp"

class DrawCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // DRAW_COMMANDD_HPP