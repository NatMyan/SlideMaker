#ifndef ADD_COMMANDD_HPP
#define ADD_COMMANDD_HPP

#include "Command.hpp"

class AddCommand : public Command {
    public:
        void execute(Map infoMap);

    private:
        static int itemID_;
};

#endif // ADD_COMMANDD_HPP