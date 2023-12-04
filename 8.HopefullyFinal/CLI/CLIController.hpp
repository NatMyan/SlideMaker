#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

class CLIController {
    public:
        CLIController(std::istream& inputStream, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);

    public:
        void execCLI();
    
    private:
        std::istream& inputStream_;
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Director> dir_;
};

#endif // CLI_CONTROLLERR_HPP