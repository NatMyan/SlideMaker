#ifndef LIST_COMMANDD_HPP
#define LIST_COMMANDD_HPP

#include "Command.hpp"

class ListCommand : public Command {
    public:
        ListCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

#endif // LIST_COMMANDD_HPP