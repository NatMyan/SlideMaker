#ifndef CLI_CONTROLLERR_HPP
#define CLI_CONTROLLERR_HPP

class CLIController {
    public:
        CLIController();

    public:
        void execCLI(std::istream& input, const char& eolToken);
        void executeCmd();
        
    // private:
        // std::shared_ptr<Document> doc_;
        // std::shared_ptr<Director> dir_;
        // std::shared_ptr<Renderer> rend_;
        // std::shared_ptr<Serializer> srlz_;
};

#endif // CLI_CONTROLLERR_HPP