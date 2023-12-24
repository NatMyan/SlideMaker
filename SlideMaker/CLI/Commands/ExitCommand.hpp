#ifndef EXIT_COMMANDD_HPP
#define EXIT_COMMANDD_HPP

#include "Command.hpp"

class ExitCommand : public Command {
    public:
        ExitCommand(const Map& info);
        void execute();

    private:
        Map info_;
};

#endif // EXIT_COMMANDD_HPP