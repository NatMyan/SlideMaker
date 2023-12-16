#include "InputReader.hpp"

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

    //TK: Returning reference to local object constructed on the stack, after return your object will be deleted and reference will be invalid
    return lineStream;
    // return inputStream;
}