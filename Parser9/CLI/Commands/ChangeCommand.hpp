#ifndef CHANGE_COMMANDD_HPP
#define CHANGE_COMMANDD_HPP

#include "Command.hpp"
#include "../../Data/Slide.hpp"

namespace cli {

class ChangeCommand : public Command {
    struct InvalidIDException : public Exception { using Exception::Exception; };
    struct InvalidActionException : public Exception { using Exception::Exception; };
    struct InvalidItemException : public Exception { using Exception::Exception; };    
    struct InvalidSlideException : public Exception { using Exception::Exception; };

    public:
        ChangeCommand(const Map& info);
        void execute();
    
    private:
        Map createNecessaryInfo();

    private:
        Map infoMap_;
};

}

#endif // CHANGE_COMMANDD_HPP