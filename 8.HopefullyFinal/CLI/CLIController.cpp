#include "CLIController.hpp"
#include "Commands/Command.hpp"
#include "Parser8/Parser8.hpp"

CLIController::CLIController(std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) :
    doc_(doc),
    dir_(dir)
{}

void CLIController::execCLI(std::istream& input) {
    Parser8 parser(input, eolToken);
    if (parser.isCommandValid()) {
        const CommandInfo cmdInfo = parser.constructCommandInfo(input, eolToken);
        CommandHistory::append(cmdInfo);
        std::shared_ptr<Command> parsedCmd = parser.constructCommand();
        const auto& infoMap = cmdInfo.second;
        parsedCmd->execute(infoMap);
    }
}

/*try {
    parsedCmd = parser.constructCommand();
}
catch (const Exception& e) {
    ///TODO: handle exception
}*/

// docPtr_ = std::make_shared<Document>(); 
    /*while (!exit) {
        InputReader inputReader;
        const char eolToken = '\n';
        auto inputStr = inputReader.readInputLine(input, eolToken);

        // CommandHistory history;
        // history.append(inputStr);
        CommandHistory::append(inputStr);

        Parser7 parser;
        auto parsedCmd = parser.parseCommand(inputStr, eolToken);

        CommandValidator validator;
        if (validator.isCommandValid(parsedCmd)) {
            if (parsedCmd.get<0>() == "exit")
                break;
            Command cmd->execute();  // creates what needs to be created in it
            // ActionTaker action; //call from GUI, CLI 
            // action.execute(parsedCmd, docPtr_);
            
        } 
    }*/