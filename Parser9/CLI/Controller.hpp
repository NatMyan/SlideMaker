#ifndef CONTROLLERR_HPP
#define CONTROLLERR_HPP

#include "CommandHistory.hpp"
#include "CommandFactory.hpp"

#include <memory>

namespace cli {

class Controller {
    struct InvalidCommandException : public Exception { using Exception::Exception; };

    public:
        Controller(std::istream& inputStream, std::ostream& outputStream);

    public:
        void execCLI(std::istream& input, const char& eolToken);
        void execOnce(const char& eolToken);
        std::istream& getInputStream(); // no smart ptr for streams 
        std::ostream& getOutputStream();        

    private:
        std::string readInput(std::istream& input, const char& eolToken);
        
    private:
        std::shared_ptr<CommandHistory> history_;
        std::shared_ptr<CommandFactory> cmdFactory_;
        std::istream& inputStream_;
        std::ostream& outputStream_;
        bool isExit = false;
};

}

#endif // CONTROLLERR_HPP