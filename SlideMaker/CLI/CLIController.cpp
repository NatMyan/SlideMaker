#include "CLIController.hpp"
#include "Commands/Command.hpp"
#include "Parser8/Parser8.hpp"

#include <sstream>
#include <iostream>

CLIController::CLIController(std::istream& inputStream, std::ostream& outputStream) :
    history_(std::make_shared<CommandHistory>()),
    cmdFactory_(std::make_shared<CommandFactory>()),
    inputStream_(inputStream),
    outputStream_(outputStream) 
    ///TODO: cmdFactory_ as data member or in the exec method ?
{}

std::ostream& CLIController::getOutputStream() {
    return outputStream_;
}

std::istream& CLIController::getInputStream() {
    return inputStream_;
}

void CLIController::execCLI(std::istream& input, const char& eolToken) {
    while (!isExit) {
        execOnce(eolToken);
    }
}

void CLIController::execOnce(const char& eolToken) {
    // const char eolToken = '\n';
    std::string strLine = readInputLine(inputStream_, eolToken);  
    std::stringstream input2(strLine);
    // std::cout << input2.str() << " hi " << strLine << std::endl;
    Parser8 parser(cmdFactory_, input2, eolToken);
    // std::cout << input2.str() << " weed " << strLine << std::endl;
    std::shared_ptr<Command> pCmd = parser.parseCommand();
    // std::cout << input2.str() << " hi there " << strLine << std::endl;
    if (pCmd) {
        // std::cout << "cmd success" << std::endl;
        pCmd->execute();
    }
    // std::cout << input2.str() << " great " << strLine << std::endl;
    history_->append(parser.createCmdString());
    // std::string strCmd = parser.createCmdString();  // done like this to avoid mid-state situation if there's any exception
}

std::string CLIController::readInputLine(std::istream& input, const char& eolToken) {
    std::string line;
    char currentChar;
    
    while (input.get(currentChar)) {
        if (currentChar == eolToken) {
            break;
        }
        line += currentChar;
    }

    return line;
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