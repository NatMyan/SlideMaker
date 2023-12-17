#include "Application.hpp"

///TODO: since static, put them outside of Application
Application::Application() // :
    // reader_(std::make_shared<InputReader>()),
    // ctr_ (std::make_shared<CLIController>()),
    // doc_ (std::make_shared<Document>()),
    // dir_ (std::make_shared<Director>()), 
    // rend_ (std::make_shared<Renderer>())
    // srlz_(std::make_shared<Serializer>())
{
    // reader_ = std::make_shared<InputReader>();
    // ctr_ = std::make_shared<CLIController>();
    // doc_ = std::make_shared<Document>();
    // dir_ = std::make_shared<Director>(); 
    // rend_ = std::make_shared<Renderer>();
    // setStreams(inputStream, outputStream);
}

Application::~Application() = default;

std::shared_ptr<Application> Application::getApplication() {
    static std::shared_ptr<Application> instance;
    return instance;
}

void Application::setStreams(std::istream& inputStream, std::ostream& outputStream) {
    inputStream_ = std::make_shared<std::istream>(&inputStream);
    outputStream_ = std::make_shared<std::ostream>(&outputStream);
}

void Application::exec(std::istream& inputStream, std::ostream& outputStream) {
    setStreams(inputStream, outputStream);
    while (!needToExit_) {
        const char eolToken = '\n';
        std::istream& input = reader_->readInputLine(inputStream, eolToken);
        getCLIController()->execCLI(inputStream, eolToken);
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
    static std::shared_ptr<CLIController> ctr_;
    if (!ctr_)
        ctr_ = std::make_shared<CLIController>();
    return ctr_;
}

std::shared_ptr<std::ostream> Application::getOutputStream() {
    static std::shared_ptr<std::ostream> outputStream_;
    if (!outputStream_)
        outputStream_ = std::make_shared<std::ostream>();
    return outputStream_;
}

std::shared_ptr<std::istream> Application::getInputStream() {
    static std::shared_ptr<std::istream> inputStream_;
    if (!inputStream_)
        inputStream_ = std::make_shared<std::istream>();
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

