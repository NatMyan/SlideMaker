#ifndef REMOVE_COMMANDD_HPP
#define REMOVE_COMMANDD_HPP

#include "Command.hpp"

class RemoveCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // REMOVE_COMMANDD_HPP