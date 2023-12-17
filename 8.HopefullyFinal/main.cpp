#include "Application.hpp"

#include <iostream>

int main() {
    std::istream& inputStream = std::cin;
    std::ostream& outputStream = std::cout;
    std::shared_ptr<Application> a = Application::getApplication();
    // Application& a(inputStream, outputStream);
    
    // MainWindow w;
    // w.show();
    a->exec(inputStream, outputStream);
}