#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Data/Document.hpp"
#include "Rendering/Renderer.hpp"
#include "Director/Director.hpp"
#include "CLI/CLIController.hpp"
// #include "CLI/InputReader.hpp"

#include <memory>
#include <functional>

class Application {
    public:    
        static Application* getApplication();

    public:
        void exec(std::istream& inputStream, std::ostream& outputStream);  // without loop
        void quit();
        // void run(); // with loop

    public:
        std::shared_ptr<Document> getDocument();
        std::shared_ptr<Director> getDirector();
        std::shared_ptr<Renderer> getRenderer();
        std::shared_ptr<CLIController> getCLIController();
        // void setStreams(std::istream& inputStream, std::ostream& outputStream);
        // std::shared_ptr<Serializer> getSerializer();

    private:
        Application(); // = default;
        ~Application() = default;

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
    
    private:
        bool needToExit_ = false;
        static std::shared_ptr<CLIController> ctr_;
        // std::reference_wrapper<std::istream> inputStream_;
        // std::reference_wrapper<std::ostream> outputStream_;
        // std::shared_ptr<InputReader> reader_;
        // std::shared_ptr<Document> doc_;
        // std::shared_ptr<Director> dir_;
        // std::shared_ptr<Renderer> rend_;
        // std::shared_ptr<Serializer> srlz_;
};

#endif // APPLICATION_HPP

