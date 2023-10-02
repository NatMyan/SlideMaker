#include "InputReader.hpp"

std::istream& InputReader::readInputLine (std::istream& input, char endOfLineToken) {
    // std::getline(input, line);
    // return input; 
    char currentChar;
    std::string line;
    // line.clear();

    while (input.get(currentChar)) {
        if (currentChar == endOfLineToken) {
            break;
        }
        line += currentChar;
    }
    // std::string line(std::istreambuf_iterator<char>(input), {});

    return input;
}