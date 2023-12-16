#include "CLIController.hpp"
#include "Commands/Command.hpp"
#include "Parser8/Parser8.hpp"

CLIController::CLIController() :
    history_(std::make_shared<CommandHistory>())
    // doc_(doc),
    // dir_(dir)
{}

void CLIController::exec() {
    //TK: organize your main loop here
    while (!exit_) {
        const char eolToken = '\n';
        //TK: readInputLine should be part of controller (private), your reader class is artificial, you do not need it 
        std::string strLine = readInputLine();  
        std::stringstream input(strLine);
        //TK: but if you will organize your parser more correctly you do not need this readInputLine and stringstream either
        // since you are passing end of line to your parser it should be able to parse single line from your main input swtream directly 
        execOnce(input, eolToken);
        //TK: could be like this instead
        //execOnce(inputStream_, eolToken);
    }

}
void CLIController::execOnce(std::istream& input, const char& eolToken) {
    //TK: this function need to be for single execution 
    Parser8 parser(input, eolToken);
    //while (!exit) {
        // std::string strCmd = parser.createCmdString();  // done like this to avoid mid-state situation if there's any exception
        std::shared_ptr<Command> pCmd = parser.parseCommand();
        pCmd->execute();
        history_->append(parser.createCmdString());
    //}
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