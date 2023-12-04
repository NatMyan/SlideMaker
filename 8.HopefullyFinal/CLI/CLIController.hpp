#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

class CLIController {
    public:
        CLIController(std::shared_ptr<Document> doc, std::shared_ptr<Director> dir, std::shared_ptr<Renderer> rend, std::shared_ptr<Serializer> srlz);

    public:
        void execCLI(std::istream& input);
    
    private:
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Director> dir_;
        std::shared_ptr<Renderer> rend_;
        std::shared_ptr<Serializer> srlz_;
};

#endif // CLI_CONTROLLERR_HPP