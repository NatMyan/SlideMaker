#include "CmdController.hpp"

#include "InputReader.hpp"
#include "Parser6.hpp"
#include "CommandValidator.hpp"
#include "../Director/ActionTaker.hpp"

void CmdController::run(std::istream& input) {
    exec(input);
}

///TODO: catch exceptions
void CmdController::exec(std::istream& input) {
    while(!exit) {
        InputReader inputReader;
        const char eolToken = '\n';
        auto inputStr = inputReader.readInputLine(input, eolToken);

        Parser6 parser;
        auto parsedCmd = parser.parseCommand(inputStr, eolToken);

        CommandValidator validator;
        if (validator.isCommandValid(parsedCmd)) {
            if (parsedCmd.get<0>() == "exit")
                break;
            ActionTaker action;
            action.execute(parsedCmd);
        } 
    }
}