#include <iostream>

std::string readInputLine (std::istream& input) {
    std::string line;
    std::getline(input, line);
    return line;
}