#ifndef CLI_CONTROLLER_HPP
#define CLI_CONTROLLER_HPP

#include "../Data/Document.hpp"

#include <istream>

class CLIController {
    public:
        void run(std::istream& input);

    private:
        void exec(std::istream& input);
    
    private:
        std::shared_ptr<Document> docPtr_;
        bool exit_ = false;
};

#endif // CLI_CONTROLLER_HPP