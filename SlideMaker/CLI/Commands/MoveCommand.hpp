#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include "Command.hpp"

class MoveCommand : public Command {
    public:
        MoveCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

#endif // MOVE_COMMAND_HPP