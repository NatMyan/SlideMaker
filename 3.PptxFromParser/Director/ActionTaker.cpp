#include "ActionTaker.hpp"

void ActionTaker::execute(CommandType parsedCmd) {
    auto commandToExecute = CommandFactory::createCommand(parsedCmd.get<0>());
    commandToExecute->execute(parsedCmd);
}