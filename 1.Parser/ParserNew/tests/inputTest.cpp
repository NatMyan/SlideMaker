#include <iostream>
#include <sstream>

std::string readInput (std::istream& input) {
    std::string line;
    std::getline(input, line);
    return line;
}

int main () {
    std::istringstream input_stream("Line 1\nLine 2\nLine 3");
    std::cout << readInput(input_stream) << std::endl; // Line 1
}