#include "Application.hpp"
#include "zhelpers/Exception.hpp"

#include <iostream>

namespace app {

std::shared_ptr<Controller> Application::ctr_;

Application::Application() {}

Application* Application::getApplication() {
    static Application instance; 
    return &instance;
}

void Application::exec(std::istream& inputStream, std::ostream& outputStream) {
    ctr_ = std::make_shared<Controller>(inputStream, outputStream);
    while (!isExit_) {
        const char eolToken = '\n';
        try {
            std::cout << "Ctr starting" << std::endl;
            ctr_->execOnce(eolToken); 
            // std::cout << "exec" << std::endl;
        }
        catch (const Exception& e) {
            std::cout << "continue" << std::endl;
            continue;
            // std::cout << "Exception caught in Application exec, now what?" << std::endl;
        }
    }
}

void Application::quit() {
    isExit_ = true;
}

std::shared_ptr<Document> Application::getDocument() {
    static std::shared_ptr<Document> doc_;
    if (!doc_)
        doc_ = std::make_shared<Document>();
    return doc_;
}

std::shared_ptr<Director> Application::getDirector() {
    static std::shared_ptr<Director> dir_;
    if (!dir_)
        dir_ = std::make_shared<Director>();
    return dir_;
}

std::shared_ptr<Controller> Application::getController() {
    assert(ctr_ != nullptr);
    return ctr_;
}

}

/*std::shared_ptr<Renderer> Application::getRenderer() {
    static std::shared_ptr<Renderer> rend_;
    if (!rend_)
        rend_ = std::make_shared<Renderer>();
    return rend_;
}*/