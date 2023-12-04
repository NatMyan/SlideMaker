#include "CmdLineInterface/CmdController.hpp"

#include <iostream>

int main() {
    std::istream& inputStreamObj = std::cin;
    CmdController cmdController;
    cmdController.run(inputStreamObj);
}