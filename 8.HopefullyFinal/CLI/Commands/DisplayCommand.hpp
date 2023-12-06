#ifndef DISPLAY_COMMANDD_HPP
#define DISPLAY_COMMANDD_HPP

#include "Command.hpp"

class DisplayCommand : public Command {
    public:
        DisplayCommand(const Map& info);
        void execute();

    private:
        Map info_;
};

#endif // DISPLAY_COMMANDD_HPP