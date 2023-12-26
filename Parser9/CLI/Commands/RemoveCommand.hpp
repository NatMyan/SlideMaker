#ifndef REMOVE_COMMANDD_HPP
#define REMOVE_COMMANDD_HPP

#include "Command.hpp"

namespace cli {

class RemoveCommand : public Command {
    struct InvalidActionException : public Exception { using Exception::Exception; };
    struct InvalidIDException : public Exception { using Exception::Exception; };
    struct InvalidSlideException : public Exception { using Exception::Exception; };

    public:
        RemoveCommand(const Map& info);
        void execute();

    private:    
        bool isArgFound(const std::string& argName);
        bool isSlide();
        bool isItem();

    private:
        Map infoMap_;
};

}

#endif // REMOVE_COMMANDD_HPP
