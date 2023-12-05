#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

class Application {
    public:    
        Application(std::istream& inputStream);

    public:
        void exec(); // with loop
        void run();  // without loop

    public:
        ///TODO: static or not ?
        std::shared_ptr<Document> getDocument();
        std::shared_ptr<Director> getDirector();
        std::shared_ptr<Renderer> getRenderer();
        std::shared_ptr<Serializer> getSerializer();
        // std::shared_ptr<CLIController> getCLIController();
    
    private:
        std::istream& inputStream_;
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Director> dir_;
        std::shared_ptr<Renderer> rend_;
        std::shared_ptr<Serializer> srlz_;
        std::shared_ptr<CLIController> ctr_;
};

#endif // APPLICATION_HPP