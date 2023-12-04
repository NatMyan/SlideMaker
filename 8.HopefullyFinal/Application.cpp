#include "Application.hpp"

Application::Application(std::istream& inputStream) :
    inputStream_(inputStream),
    doc_(std::make_shared<Document>()),
    dir_(std::make_shared<Director>()),
    rend_(std::make_shared<Renderer>()),
    srlz_(std::make_shared<Serializer>())
{
    ctr_ = std::make_shared<CLIController>(dir_, doc_, rend_, srlz_);
}

///NOTE: Enters the main event loop and waits until exit() is called, (IN QT)
//       then returns the value that was set to exit() (which is 0 if exit() is called via quit()).
void Application::exec() {

}

void Application::run() {
    const char eolToken = '\n';
    std::istream& input = InputReader::readInputLine(inputStream_, eolToken);
    ctr_->execCLI(input);
}