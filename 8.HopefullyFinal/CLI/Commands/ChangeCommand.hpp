#ifndef CHANGE_COMMANDD_HPP
#define CHANGE_COMMANDD_HPP

#include "Command.hpp"

class ChangeCommand : public Command {
    public:
        ChangeCommand(const Map& info);
        void execute();
    
    private:
        Map createNecessaryInfo();

    private:
        Map infoMap_;
};

#endif // CHANGE_COMMANDD_HPP