#ifndef REMOVE_COMMANDD_HPP
#define REMOVE_COMMANDD_HPP

#include "Command.hpp"

class RemoveCommand : public Command {
    public:
        RemoveCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

#endif // REMOVE_COMMANDD_HPP