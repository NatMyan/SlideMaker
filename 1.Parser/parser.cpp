#include "parser.hpp"

#include <iostream>

void Parser::run () {
    printHeader();
    while (true) {
        exec();
    }
}

void Parser::exec() {
    std::string command;
    inputCommand(command);
    const std::string result = computeResult(command);
    printResult(result);
}

void Parser::printHeader() {
    std::cout << "Input action and the corresponding operand(s):" << std::endl;
}

void Parser::inputCommand(std::string command) {
    std::cin >> command;
}

/// TODO: this is test, turn it into a working code
std::string Parser::computeResult(std::string command) {
    /*
    check the first 2-4 letters for command
    convert the numbers to int/float (stoi, stof, etc) [probably easier to use variadic templates, instead of 1 command]
    switch case the result computation, I guess
    */
    return "hi";
}

void Parser::printResult(std::string result) {
    std::cout << result << std::endl;
}