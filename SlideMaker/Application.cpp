#include "Application.hpp"

std::shared_ptr<CLIController> Application::ctr_;

///TODO: since static, put them outside of Application
Application::Application() {}

Application* Application::getApplication() {
    static Application instance; 
    /*if (!instance) {
        instance = std::make_shared<Application>();
    }*/
    return &instance;
}

void Application::exec(std::istream& inputStream, std::ostream& outputStream) {
    // setStreams(inputStream, outputStream);
    ctr_ = std::make_shared<CLIController>(inputStream, outputStream);
    while (!needToExit_) {
        const char eolToken = '\n';
        ctr_->execOnce(eolToken); 
        ///TODO: there should be 1 loop, right ?
    }
}

void Application::quit() {
    needToExit_ = true;
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

std::shared_ptr<Renderer> Application::getRenderer() {
    static std::shared_ptr<Renderer> rend_;
    if (!rend_)
        rend_ = std::make_shared<Renderer>();
    return rend_;
}

std::shared_ptr<CLIController> Application::getCLIController() {
    assert(ctr_ != nullptr);
    return ctr_;
}



/*void Application::setStreams(std::istream& inputStream, std::ostream& outputStream) {
    inputStream_ = inputStream;
    outputStream_ = outputStream;
}*/

/*
std::shared_ptr<Serializer> Application::getSerializer() {
    return srlz_;
}
*/


