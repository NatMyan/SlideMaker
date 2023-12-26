#ifndef SAVE_COMMANDD_HPP
#define SAVE_COMMANDD_HPP

#include "Command.hpp"

namespace cli {

class SaveCommand : public Command {
    struct InvalidFileException : public Exception { using Exception::Exception; };
    
    public:
        SaveCommand(const Map& info);
        void execute();

    private:
        Map infoMap_;
};

}

#endif // SAVE_COMMANDD_HPP