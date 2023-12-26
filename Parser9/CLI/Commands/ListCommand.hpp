#ifndef LIST_COMMANDD_HPP
#define LIST_COMMANDD_HPP

#include "Command.hpp"

namespace cli {

class ListCommand : public Command {
    struct GroupNotFoundException : public Exception { using Exception::Exception; };

    public:
        ListCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

}

#endif // LIST_COMMANDD_HPP