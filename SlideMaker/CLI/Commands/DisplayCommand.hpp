#ifndef DISPLAY_COMMANDD_HPP
#define DISPLAY_COMMANDD_HPP

#include "Command.hpp"

class DisplayCommand : public Command {
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

#endif // DISPLAY_COMMANDD_HPP