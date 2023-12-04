#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

class Application {
    public:    
        Application(std::istream& inputStream);

    public:
        void exec(); // with loop
        void run();  // without loop
    
    private:
        std::istream& inputStream_;
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Director> dir_;
        std::shared_ptr<Renderer> rend_;
        std::shared_ptr<Serializer> srlz_;
        std::shared_ptr<CLIController> ctr_;
};

#endif // APPLICATION_HPP