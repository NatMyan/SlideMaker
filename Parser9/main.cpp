#include "Application.hpp"

#include <iostream>

using Application = app::Application;

int main() {
    Application* a = Application::getApplication();
    // MainWindow w;
    // w.show();
    a->exec(std::cin, std::cout);
}