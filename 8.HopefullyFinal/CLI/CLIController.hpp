#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

class CLIController {
    public:
        CLIController(std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);

    public:
        void execCLI(std::istream& input);
    
    private:
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Director> dir_;
};

#endif // CLI_CONTROLLERR_HPP