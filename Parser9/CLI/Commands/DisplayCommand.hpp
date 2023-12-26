#ifndef DISPLAY_COMMANDD_HPP
#define DISPLAY_COMMANDD_HPP

#include "Command.hpp"

namespace cli {
 
class DisplayCommand : public Command {
    struct InvalidIDException : public Exception { using Exception::Exception; };
    struct InvalidItemException : public Exception { using Exception::Exception; };
    struct InvalidSlideException : public Exception { using Exception::Exception; };

    public:
        DisplayCommand(const Map& info);
        void execute();
    
    private:    
        bool isArgFound(const std::string& argName);
        bool isSlide();
        bool isItem();

    private:
        Map infoMap_;
};

}

#endif // DISPLAY_COMMANDD_HPP