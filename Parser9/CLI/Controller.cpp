#include "Controller.hpp"
#include "Commands/Command.hpp"
#include "Parser8/Parser8.hpp"
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
    Parser8 parser(cmdFactory_, inputStream_, eolToken);
    std::shared_ptr<Command> pCmd = parser.parseCommand();
    auto str = parser.createCmdString();

    if (pCmd) {
        // try {
            pCmd->execute(); 
        // }
        // catch (const Exception& e) {
            // inputStream_.clear();
        //     std::cout << "Exception caught in Controller execOnce, now what?" << std::endl;
        // }
        history_->append(str);
    }
    else { 
        throw InvalidCommandException("Wrong command: " + str); 
    }
}

}

