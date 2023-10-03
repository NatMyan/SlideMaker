#include "InputReader.hpp"

std::string InputReader::readInputLine (std::istream& input, const char& endOfLineToken) {
    std::string line;
    char currentChar;

    while (input.get(currentChar)) {
        if (currentChar == endOfLineToken) {
            break;
        }
        line += currentChar;
    }

    return line;
}