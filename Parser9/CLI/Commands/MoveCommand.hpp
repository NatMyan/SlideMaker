#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include "Command.hpp"

namespace cli {

class MoveCommand : public Command {
    struct InvalidIndexException : public Exception { using Exception::Exception; };
    struct InvalidActionException : public Exception { using Exception::Exception; };

    public:
        MoveCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

}

#endif // MOVE_COMMAND_HPP