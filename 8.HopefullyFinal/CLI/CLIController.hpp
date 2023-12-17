#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

#include "CommandHistory.hpp"

#include <memory>

class CLIController {
    public:
        CLIController();

    public:
        void execCLI(std::istream& input, const char& eolToken);
        void execOnce(std::istream& input, const char& eolToken);
        // void executeCmd();
        
    private:
        std::shared_ptr<CommandHistory> history_;
        // const char eolToken = '\n';
        // std::shared_ptr<Document> doc_;
        // std::shared_ptr<Director> dir_;
        // std::shared_ptr<Renderer> rend_;
        // std::shared_ptr<Serializer> srlz_;
};

#endif // CLI_CONTROLLERR_HPP