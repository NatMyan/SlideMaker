#include "Parser3.hpp"

template <typename Operand>
CommandUnderlyingType<Operand> Parser3<Operand>::parseCommand(std::string line) {
    CommandRegistry cmdReg;    
    CommandUnderlyingType parsedCmd;

    if (cmdReg.findCommand(line)) {
        Command cmdStruct;
        parsedCmd = cmdStruct.addArgument(line);
    }

    return parsedCmd;
}