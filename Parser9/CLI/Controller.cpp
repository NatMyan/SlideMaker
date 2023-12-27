#include "Controller.hpp"
#include "Commands/Command.hpp"
#include "Parser9/Parser9.hpp"
#include "../zhelpers/Exception.hpp"

#include <sstream>
#include <iostream>

namespace cli {

Controller::Controller(std::istream& inputStream, std::ostream& outputStream) :
    history_(std::make_shared<CommandHistory>()),
    cmdFactory_(std::make_shared<CommandFactory>()),
    inputStream_(inputStream),
    outputStream_(outputStream) 
{}

std::ostream& Controller::getOutputStream() {
    return outputStream_;
}

std::istream& Controller::getInputStream() {
    return inputStream_;
}

void Controller::execCLI(std::istream& input, const char& eolToken) {
    while (!isExit) {
        // try {
            execOnce(eolToken);
        // }
        // catch (const Exception& e) {
        //     std::cout << "Exception in Controller execCLI" << std::endl;
        // }
    }
}

void Controller::execOnce(const char& eolToken) {
    std::cout << "about to parse1" << std::endl;
    std::string strLine = readInput(inputStream_, eolToken);
    std::istringstream iss(strLine);

    Parser9 parser(cmdFactory_, iss, eolToken);
    std::cout << "about to parse2" << std::endl;
    std::shared_ptr<Command> pCmd = parser.parseCommand();
    std::cout << "parsed?" << std::endl;
    auto str = parser.createCmdString();
    std::cout << "str: " << str << std::endl;

    if (pCmd) {
        // try {
            std::cout << "About to execute cmd" << std::endl;
            pCmd->execute(); 
        // }
        // catch (const Exception& e) {
            // inputStream_.clear();
        //     std::cout << "Exception caught in Controller execOnce, now what?" << std::endl;
        // }
        history_->append(str);
    }
    else { 
        std::cout << "what" << std::endl;
        throw InvalidCommandException("Wrong command: " + str); 
    }
}

std::string Controller::readInput(std::istream& input, const char& eolToken) {
    std::string inputPart;
    char currentChar;
    
    while (input.get(currentChar)) {
        if (currentChar == eolToken) {
            break;
        }
        inputPart += currentChar;
    }

    return inputPart;
}

}

