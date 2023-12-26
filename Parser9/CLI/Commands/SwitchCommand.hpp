#ifndef SWITCH_COMMANDD_HPP
#define SWITCH_COMMANDD_HPP

#include "Command.hpp"

namespace cli {

class SwitchCommand : public Command {
    struct InvalidIndexException : public Exception { using Exception::Exception; };

    public:
        SwitchCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

}

#endif // SWITCH_COMMANDD_HPP