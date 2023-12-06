#ifndef LIST_COMMANDD_HPP
#define LIST_COMMANDD_HPP

#include "Command.hpp"

class ListCommand : public Command {
    public:
        void execute(Map infoMap);
};

#endif // LIST_COMMANDD_HPP