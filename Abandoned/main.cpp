#include "CLI/CLIController.hpp"

#include <iostream>

int main() {
    std::istream& inputStreamObj = std::cin;
    CLIController cliController;
    cliController.run(inputStreamObj);
}