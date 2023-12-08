#include "Application.hpp"

#include <iostream>

int main() {
    std::istream& inputStream = std::cin;
    std::ostream& outputStream = std::cout;
    Application a(inputStream, outputStream);
    // MainWindow w;
    // w.show();
    a.exec();
}