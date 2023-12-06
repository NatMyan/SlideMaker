#ifndef UNDO_COMMANDD_HPP
#define UNDO_COMMANDD_HPP

#include "Command.hpp"

class UndoCommand : public Command {
    public:
        UndoCommand(const Map& info);
        void execute();

    private:
        Map info_;
};

#endif // UNDO_COMMANDD_HPP