#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Data/Document.hpp"
#include "Director/Director.hpp"
#include "CLI/Controller.hpp"
#include "Rendering/Renderer.hpp" // keep or nah ?

#include <memory>
#include <functional>

namespace app {

using Controller = cli::Controller;

class Application {
    public:    
        static Application* getApplication();

    public:
        void exec(std::istream& inputStream, std::ostream& outputStream);  
        void quit();

    public:
        std::shared_ptr<Controller> getController();
        std::shared_ptr<Document> getDocument();
        std::shared_ptr<Director> getDirector();
        // std::shared_ptr<Renderer> getRenderer();

    private:
        Application();
        ~Application() = default;

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
    
    private:
        bool isExit_ = false;
        static std::shared_ptr<Controller> ctr_;
};

}

#endif // APPLICATION_HPP

