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
        static std::shared_ptr<Application> getApplication();

    public:
        // void run(); // with loop
        void exec(std::istream& inputStream, std::ostream& outputStream);  // without loop
        void quit();

    public:
        ///TODO: static or not ? -> NOT
        std::shared_ptr<std::istream> getInputStream();
        std::shared_ptr<std::ostream> getOutputStream();
        void setStreams(std::istream& inputStream, std::ostream& outputStream);

        std::shared_ptr<Document> getDocument();
        std::shared_ptr<Director> getDirector();
        std::shared_ptr<Renderer> getRenderer();
        std::shared_ptr<CLIController> getCLIController();
        // std::shared_ptr<Serializer> getSerializer();

    private:
        Application();
        ~Application();

        Application(const Application&)= delete;
        Application& operator=(const Application&)= delete;
    
    private:
        std::shared_ptr<std::istream> inputStream_;
        std::shared_ptr<std::ostream> outputStream_;
        std::shared_ptr<InputReader> reader_;
        bool needToExit_ = false;
        // std::shared_ptr<Document> doc_;
        // std::shared_ptr<Director> dir_;
        // std::shared_ptr<Renderer> rend_;
        // std::shared_ptr<CLIController> ctr_;
        // std::shared_ptr<Serializer> srlz_;
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