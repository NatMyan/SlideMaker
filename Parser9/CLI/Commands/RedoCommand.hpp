#ifndef REDO_COMMANDD_HPP
#define REDO_COMMANDD_HPP

#include "Command.hpp"

class RedoCommand : public Command {
    public:
        RedoCommand(const Map& info);
        void execute();

    private:
        Map info_;
};

#endif // REDO_COMMANDD_HPP