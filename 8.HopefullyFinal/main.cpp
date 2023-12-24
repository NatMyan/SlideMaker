#include "Application.hpp"

#include <iostream>

int main() {
    Application* a = Application::getApplication();
    // MainWindow w;
    // w.show();
    a->exec(std::cin, std::cout);
}