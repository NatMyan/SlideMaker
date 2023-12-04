#include "CmdController.hpp"

#include "InputReader.hpp"
#include "Parser6.hpp"
#include "CommandValidator.hpp"
#include "../Director/ActionTaker.hpp"

#include <iostream>

void CmdController::run(std::istream& input) {
    exec(input);
}

///TODO: catch exceptions
void CmdController::exec(std::istream& input) {
    auto docPtr = std::make_shared<Document>();
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
            // try {
                ActionTaker action;
                action.execute(parsedCmd, docPtr);
            // } catch (const std::bad_variant_access&) {
                // std::cerr << "bad variant access" << std::endl;
            // }
        } 
    }
}