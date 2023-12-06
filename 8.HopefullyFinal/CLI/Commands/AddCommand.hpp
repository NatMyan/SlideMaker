#ifndef ADD_COMMANDD_HPP
#define ADD_COMMANDD_HPP

#include "Command.hpp"

class AddCommand : public Command {
    public:
        AddCommand(const Map& info);
        void execute();

    private:
        static int itemID_;
        Map info_;
};

#endif // ADD_COMMANDD_HPP