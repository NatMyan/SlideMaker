#include "Printer.hpp"

#include <iostream>

// template <typename Operand>
void Printer::printResult (double result) {
    std::cout << "Result: " << result << std::endl;
}

void Printer::printInvalidCommandError() {
    std::cerr << "Error: Invalid command. Try again." << std::endl;
}