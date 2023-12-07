#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Data/Document.hpp"

#include <memory>

class Application {
    public:    
        Application(std::istream& inputStream);

    public:
        void exec(); // with loop
        void run();  // without loop

    public:
        ///TODO: static or not ?
        static std::shared_ptr<Document> getDocument();
        static std::shared_ptr<Director> getDirector();
        static std::shared_ptr<Renderer> getRenderer();
        static std::shared_ptr<CLIController> getCLIController();
        // static std::shared_ptr<Serializer> getSerializer();
    
    private:
        std::istream& inputStream_;
        static std::shared_ptr<Document> doc_;
        static std::shared_ptr<Director> dir_;
        static std::shared_ptr<Renderer> rend_;
        static std::shared_ptr<CLIController> ctr_;
        // static std::shared_ptr<Serializer> srlz_;
        std::shared_ptr<InputReader> reader_;
};

#endif // APPLICATION_HPP