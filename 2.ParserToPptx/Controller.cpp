#include "Controller.hpp"

#include <iostream>

void Controller::run() {
    while (true) {
        std::istream& inputStream = std::cin;
        InputReader inputReader;

        char endOfLineToken = '\n';
        auto input = inputReader.readInputLine(inputStream, endOfLineToken); // yikes

        Parser4 parser;
        auto command = parser.parseCommand(input, endOfLineToken);

        // if (std::holds_alternative<CommandType>(command)) {
            // CommandType cmd = std::get<CommandType>(command);
            CommandType cmd = command;
            CommandValidator validator;

            if (validator.isCommandValid(cmd)) {
                std::string cmdName = std::get<0>(cmd);
                CommandExecutorFactory execFactory;
                std::unique_ptr<CommandExecutor> executor = execFactory.createCommandExecutor(cmdName);
                ///TODO: bnakanabar change this hors arev
                
                if (executor == nullptr) {
                    std::string errorMsg = "wrong_command_2";
                    /// TODO: parser checks for the right command, there should be no need for this
                    Printer printer;
                    printer.printErrorMsg (errorMsg);
                }
                else {
                    executor->execute(cmd);
                }
            }
            else {
                std::string errorMsg = "semantically_incorrect";
                Printer printer;
                printer.printErrorMsg (errorMsg);
            }
        /*}
        else if (std::holds_alternative<std::string>(command)) {
            std::string errorMsg = std::get<std::string>(command);
            Printer printer;
            printer.printErrorMsg (errorMsg);
        }*/
    }
}