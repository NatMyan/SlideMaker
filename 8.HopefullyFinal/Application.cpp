#include "Application.hpp"

///TODO: since static, put them outside of Application
Application::Application(std::istream& inputStream, std::ostream& outputStream) :
    reader_(std::make_shared<InputReader>())
    // srlz_(std::make_shared<Serializer>())
{
    setStreams(inputStream, outputStream);
    ctr_ = std::make_shared<CLIController>();
    doc_ = std::make_shared<Document>();
    dir_ = std::make_shared<Director>(); 
    rend_ = std::make_shared<Renderer>();
}

void Application::setStreams(std::istream& inputStream, std::ostream& outputStream) {
    inputStream_ = std::make_shared<std::istream>(&inputStream);
    outputStream_ = std::make_shared<std::ostream>(&outputStream);
}

///TODO: to be fixed
///NOTE: Enters the main event loop and waits until exit() is called, (IN QT)
//       then returns the value that was set to exit() (which is 0 if exit() is called via quit()).
void Application::exec() {
    
}

void Application::run() {
    const char eolToken = '\n';
    std::istream& input = reader_->readInputLine(*inputStream_, eolToken);
    ctr_->execCLI(input, eolToken);
}

std::shared_ptr<Document> Application::getDocument() {
    return doc_;
}

std::shared_ptr<Director> Application::getDirector() {
    return dir_;
}

std::shared_ptr<Renderer> Application::getRenderer() {
    return rend_;
}

std::shared_ptr<CLIController> Application::getCLIController() {
    return ctr_;
}

std::shared_ptr<std::ostream> Application::getOutputStream() {
    return outputStream_;
}

std::shared_ptr<std::istream> Application::getInputStream() {
    return inputStream_;
}

/*
std::shared_ptr<Serializer> Application::getSerializer() {
    return srlz_;
}
*/

