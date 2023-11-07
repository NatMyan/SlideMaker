#include "ActionTaker.hpp"

void ActionTaker::execute(CommandType parsedCmd, std::shared_ptr<Document> doc) {
    auto commandToExecute = CommandFactory::createCommand(parsedCmd.get<0>());
    commandToExecute->execute(parsedCmd, doc);
}