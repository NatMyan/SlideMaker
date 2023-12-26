#ifndef DRAW_COMMANDD_HPP
#define DRAW_COMMANDD_HPP

#include "Command.hpp"

namespace cli {

class DrawCommand : public Command {
    struct InvalidFileException : public Exception { using Exception::Exception; };
    struct FailedToSaveException : public Exception { using Exception::Exception; };
    struct FileExistsException : public Exception { using Exception::Exception; };
    struct FileDidNotOpenException : public Exception { using Exception::Exception; };
    struct InvalidSlideException : public Exception { using Exception::Exception; };

    public:
        DrawCommand(const Map& info);
        void execute();
    
    private:    
        ID takeIndex();
        std::pair<double, double> takeConvertedSize();

    private:
        Map infoMap_;
};

}

#endif // DRAW_COMMANDD_HPP