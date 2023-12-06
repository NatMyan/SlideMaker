#ifndef UNDO_COMMANDD_HPP
#define UNDO_COMMANDD_HPP

#include "Command.hpp"

class UndoCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // UNDO_COMMANDD_HPP