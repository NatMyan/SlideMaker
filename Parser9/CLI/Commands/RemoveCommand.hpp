#ifndef REMOVE_COMMANDD_HPP
#define REMOVE_COMMANDD_HPP

#include "Command.hpp"

class RemoveCommand : public Command {
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

#endif // REMOVE_COMMANDD_HPP