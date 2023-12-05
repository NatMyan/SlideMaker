#ifndef DISPLAY_COMMANDD_HPP
#define DISPLAY_COMMANDD_HPP

#include "Command.hpp"

class DisplayCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // DISPLAY_COMMANDD_HPP