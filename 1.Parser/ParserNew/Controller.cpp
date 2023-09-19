#include "Controller.hpp"

void Controller::run() {
    while (true) {
        double result;

        InputReader inputReader;
        auto input = inputReader.readInputLine();

        Parser3 prs;
        auto parsedCommand = prs.parseCommand(input);

        CommandValidator validator;
        Printer printer;

        if (validator.isCommandValid(parsedCommand)) {
            CommandExecutor executor;
            result = executor.executeCommand(parsedCommand);
            printer.printResult(result);
        }
        else {
            printer.printInvalidCommandError();
        }
    }
}