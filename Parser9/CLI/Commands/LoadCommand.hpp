#ifndef LOAD_COMMANDD_HPP
#define LOAD_COMMANDD_HPP

#include "Command.hpp"

#include <ios>

namespace cli {

class LoadCommand : public Command {
    struct InvalidFileException : public Exception { using Exception::Exception; };
    
    public:
        LoadCommand(const Map& info);
        void execute();

    private:
        std::streamsize takeFileSize(std::ifstream& file);

    private:
        Map infoMap_;
};

}

#endif // LOAD_COMMANDD_HPP