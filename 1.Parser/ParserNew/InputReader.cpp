#include "InputReader.hpp"

#include <iostream>

std::string InputReader::readInputLine () {
    std::string line;
    std::getline(std::cin, line);
    return line;
}