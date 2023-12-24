/*#include "InputReader.hpp"

#include <sstream>

std::istream& InputReader::readInputLine (std::istream& input, const char& endOfLineToken) {
    std::string line;
    char currentChar;

    while (input.get(currentChar)) {
        if (currentChar == endOfLineToken) {
            break;
        }
        line += currentChar;
    }

    std::istringstream lineStream(line);
    // std::istream& inputStream = lineStream;

    return lineStream;
    // return inputStream;
}*/