#include "Application.hpp"

#include <iostream>

int main() {
    std::istream& inputStream = std::cin;
    Application a(inputStream);
    // MainWindow w;
    // w.show();
    a.exec();
}