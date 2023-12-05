#ifndef CHANGE_COMMANDD_HPP
#define CHANGE_COMMANDD_HPP

#include "Command.hpp"

class ChangeCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // CHANGE_COMMANDD_HPP