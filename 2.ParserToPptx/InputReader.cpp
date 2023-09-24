#include "InputReader.hpp"

std::istream& InputReader::readInputLine (std::istream& input, std::string& line) {
    std::getline(input, line);
    return input; 
}