#include "CLIController.hpp"
#include "Commands/Command.hpp"
#include "Parser8/Parser8.hpp"

CLIController::CLIController() :
    history_(std::make_shared<CommandHistory>())
    // doc_(doc),
    // dir_(dir)
{}

void CLIController::execCLI(std::istream& input, const char& eolToken) {
    Parser8 parser(input, eolToken);
    while (!exit) {
        std::string strCmd;
        std::shared_ptr<Command> parsedCmd = parser.parseCommand(strCmd);
        parsedCmd->execute();
        history->add(strCmd);
    }
}

/*if (parser.isCommandValid()) {
    const CommandInfo cmdInfo = parser.constructCommandInfo(input, eolToken);
    CommandHistory::append(cmdInfo);
    std::shared_ptr<Command> parsedCmd = parser.constructCommand();
    parsedCmd->execute();
}*/

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