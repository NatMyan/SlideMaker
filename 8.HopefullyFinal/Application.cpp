#include "Application.hpp"

///TODO: since static, put them outside of Application
Application::Application(std::istream& inputStream, std::ostream& outputStream) // :
    // reader_(std::make_shared<InputReader>()),
    // ctr_ (std::make_shared<CLIController>()),
    // doc_ (std::make_shared<Document>()),
    // dir_ (std::make_shared<Director>()), 
    // rend_ (std::make_shared<Renderer>())
    // srlz_(std::make_shared<Serializer>())
{
    reader_ = std::make_shared<InputReader>();
    ctr_ = std::make_shared<CLIController>();
    doc_ = std::make_shared<Document>();
    dir_ = std::make_shared<Director>(); 
    rend_ = std::make_shared<Renderer>();
    setStreams(inputStream, outputStream);
}

Application::~Application() = default;

Application& Application::getApplication(std::istream& inputStream, std::ostream& outputStream) {
    //TK: to be safe singletone use static shared_ptr and create application upon first request
    // You should not create Application instance before the main() function call
    static Application instance(inputStream, outputStream);
    return instance;
}

void Application::setStreams(std::istream& inputStream, std::ostream& outputStream) {
    //TK: Pass streams to the controller instead keeping them in the application
    inputStream_ = std::make_shared<std::istream>(&inputStream);
    outputStream_ = std::make_shared<std::ostream>(&outputStream);
}

///TODO: to be fixed
///NOTE: Enters the main event loop and waits until exit() is called, (IN QT)
//       then returns the value that was set to exit() (which is 0 if exit() is called via quit()).
void Application::exec() {
}

//TK: You need to keep either exec or run, both are same 
void Application::run() {
    //TK: organize your main loop here
    while (!needToExit_) {
        const char eolToken = '\n';
        //TK: readInputLine should be part of your execCLI, your reader class is artificial, you do not need it, your eolToken should be member of controller 
        std::string strLine = readInputLine(); // 
    std::stringstream input(strLine);

        std::istream& input = reader_->readInputLine(*inputStream_, eolToken);
        ctr_->execCLI(input, eolToken);
    }
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

/*
MeyersSingleton::~MeyersSingleton()= default; 

MeyersSingleton::MeyersSingleton() : value {0} {
    ++value;
}

int MeyersSingleton::getValue() const {
    return value;
}

MeyersSingleton& MeyersSingleton::getInstance() {
    static MeyersSingleton instance;
    return instance;
}
*/

