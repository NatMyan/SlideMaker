#include "Application.hpp"

Application::Application(std::istream& inputStream) :
    inputStream_(inputStream),
    doc_(std::make_shared<Document>()),
    dir_(std::make_shared<Director>()),
    rend_(std::make_shared<Renderer>()),
    // srlz_(std::make_shared<Serializer>())
    reader_(std::make_shared<InputReader>());
{
    ctr_ = std::make_shared<CLIController>();
}

///NOTE: Enters the main event loop and waits until exit() is called, (IN QT)
//       then returns the value that was set to exit() (which is 0 if exit() is called via quit()).
void Application::exec() {
    
}

void Application::run() {
    const char eolToken = '\n';
    std::istream& input = reader_->readInputLine(inputStream_, eolToken);
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

/*
std::shared_ptr<Serializer> Application::getSerializer() {
    return srlz_;
}
*/

