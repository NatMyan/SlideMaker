#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "Command.hpp"

class RemoveCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // REMOVE_COMMAND_HPP