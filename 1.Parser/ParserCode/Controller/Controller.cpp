#include "Controller.hpp"

#include <iostream>

void Controller::run() {
    std::cout << "Input command and operands:" << std::endl;
    while (true) {
        std::string commandToExecute, commandToExecute2;
        std::getline(std::cin, commandToExecute2);
        commandToExecute = commandToExecute2;
        std::stringstream sstreamInput;
        sstreamInput << commandToExecute;        

        CommandValidatorFacade commandValidator;
        auto isCommandValid = commandValidator.validateCommandStructure(sstreamInput);
        
        if (isCommandValid) {
            Parser2<std::string> parser(commandValidator);

            CommandExecutor<std::string> executor(parser);
            auto result = computeResult<std::string>(executor, sstreamInput);

            Printer printer;
            printer.printResult(result);
        } 
        else {
            Printer printer;
            printer.printInvalidCommandError();
        }
    }
}

/*
void Controller::run() {
    while (true) {
        std::string commandToExecute;
        std::getline(std::cin, commandToExecute);
        std::stringstream sstreamInput;
        sstreamInput << commandToExecute;

        CommandValidatorFacade commandValidator;
        auto isCommandValid = commandValidator.validateCommandStructure(sstreamInput);
        
        if (isCommandValid) {
            Parser2<std::string> parser(commandValidator);

            CommandExecutor<std::string> executor(parser);
            auto result = computeResult<std::string> (executor, sstreamInput);
            
            Printer printer;
            printer.printResult(result);
        }
        else {
            Printer printer;
            printer.printInvalidCommandError();
        }
    }
}
*/
