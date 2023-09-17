#include "Parser3.hpp"

template <typename Operand>
CommandStructureUnderlyingType<Operand> Parser3<Operand>::parseCommand(std::string line) {
    CommandRegistry cmdReg;    
    CommandStructureUnderlyingType parsedCmd;

    if (cmdReg.findCommandName(line)) {
        CommandStructure cmdStruct;
        parsedCmd = cmdStruct.rebuldCommand(line);
    }

    return parsedCmd;
}