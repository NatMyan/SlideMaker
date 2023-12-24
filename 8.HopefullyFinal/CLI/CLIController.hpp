#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

#include "CommandHistory.hpp"
#include "CommandFactory.hpp"

#include <memory>

class CLIController {
    public:
        CLIController(std::istream& inputStream, std::ostream& outputStream);

    public:
        void execCLI(std::istream& input, const char& eolToken);
        void execOnce(const char& eolToken);
        std::istream& getInputStream(); // no smart ptr for streams r.i.p.
        std::ostream& getOutputStream();

    private:
        std::string readInputLine(std::istream& input, const char& eolToken);
        
    private:
        std::shared_ptr<CommandHistory> history_;
        ///TODO: cmdFactory_ as data member or in the exec method ?
        std::shared_ptr<CommandFactory> cmdFactory_;
        std::istream& inputStream_;
        std::ostream& outputStream_;
        bool isExit = false;
        // const char eolToken = '\n';
};

#endif // CLI_CONTROLLERR_HPP