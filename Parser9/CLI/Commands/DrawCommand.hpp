#ifndef DRAW_COMMANDD_HPP
#define DRAW_COMMANDD_HPP

#include "Command.hpp"

class DrawCommand : public Command {
    public:
        DrawCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

#endif // DRAW_COMMANDD_HPP