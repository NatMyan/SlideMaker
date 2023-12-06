#ifndef CHANGE_COMMANDD_HPP
#define CHANGE_COMMANDD_HPP

#include "Command.hpp"

class ChangeCommand : public Command {
    public:
        ChangeCommand(const Map& info);
        void execute();

    private:
        Map info_;
};

#endif // CHANGE_COMMANDD_HPP