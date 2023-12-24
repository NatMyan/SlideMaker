#ifndef SAVE_COMMANDD_HPP
#define SAVE_COMMANDD_HPP

#include "Command.hpp"

class SaveCommand : public Command {
    public:
        SaveCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

#endif // SAVE_COMMANDD_HPP