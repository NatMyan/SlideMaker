#include "CLIController.hpp"
#include "InputReader.hpp"
#include "Parser7.hpp"
#include "CommandValidator.hpp"
#include "Commands/Command.hpp"

void CLIController::run(std::istream& input) {
    exec(input);
}

void CLIController::exec(std::istream& input) {
    docPtr_ = std::make_shared<Document>(); 
    while (!exit) {
        InputReader inputReader;
        const char eolToken = '\n';
        auto inputStr = inputReader.readInputLine(input, eolToken);

        CommandHistory history;
        history.append(inputStr);
        // CommandHistory::append(inputStr);

        Parser7 parser;
        auto parsedCmd = parser.parseCommand(inputStr, eolToken);

        CommandValidator validator;
        if (validator.isCommandValid(parsedCmd)) {
            if (parsedCmd.get<0>() == "exit")
                break;
            Command cmd->execute(director ptr);  // creates what needs to be created in it
            // ActionTaker action; //call from GUI, CLI 
            // action.execute(parsedCmd, docPtr_);
            
        } 
    }
}

