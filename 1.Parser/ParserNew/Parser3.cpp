#include "Parser3.hpp"

CommandUnderlyingType<double> Parser3::parseCommand(std::string line) {
    CommandRegistry cmdReg;    
    CommandUnderlyingType<double> parsedCmd;

    if (cmdReg.findCommand(line)) {
        Command cmdStruct;
        parsedCmd = cmdStruct.addArgument(line);
    }

    return parsedCmd;
}