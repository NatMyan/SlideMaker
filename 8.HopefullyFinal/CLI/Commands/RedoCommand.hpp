#ifndef REDO_COMMANDD_HPP
#define REDO_COMMANDD_HPP

#include "Command.hpp"

class ListCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // REDO_COMMANDD_HPP