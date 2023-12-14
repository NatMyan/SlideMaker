#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Data/Document.hpp"
#include "Rendering/Renderer.hpp"
#include "Director/Director.hpp"
#include "CLI/CLIController.hpp"
#include "CLI/InputReader.hpp"

#include <memory>

class Application {
    public:    
        static Application& getApplication(std::istream& inputStream, std::ostream& outputStream);

    public:
        void exec(); // with loop
        void run();  // without loop

    public:
        ///TODO: static or not ?
        static std::shared_ptr<std::istream> getInputStream();
        static std::shared_ptr<std::ostream> getOutputStream();
        void setStreams(std::istream& inputStream, std::ostream& outputStream);

        static std::shared_ptr<Document> getDocument();
        static std::shared_ptr<Director> getDirector();
        static std::shared_ptr<Renderer> getRenderer();
        static std::shared_ptr<CLIController> getCLIController();
        // static std::shared_ptr<Serializer> getSerializer();

    private:
        Application(std::istream& inputStream, std::ostream& outputStream);
        ~Application();

        Application(const Application&)= delete;
        Application& operator=(const Application&)= delete;
    
    private:
        static std::shared_ptr<std::istream> inputStream_;
        static std::shared_ptr<std::ostream> outputStream_;
        static std::shared_ptr<Document> doc_;
        static std::shared_ptr<Director> dir_;
        static std::shared_ptr<Renderer> rend_;
        static std::shared_ptr<CLIController> ctr_;
        // static std::shared_ptr<Serializer> srlz_;
        static std::shared_ptr<InputReader> reader_;
};

#endif // APPLICATION_HPP

/*
class MeyersSingleton{
    public:
        static MeyersSingleton& getInstance();
        int getValue() const;
        
    private:
        MeyersSingleton();
        ~MeyersSingleton();

        MeyersSingleton(const MeyersSingleton&)= delete;
        MeyersSingleton& operator=(const MeyersSingleton&)= delete;
    
    private:
        int value;
};
*/