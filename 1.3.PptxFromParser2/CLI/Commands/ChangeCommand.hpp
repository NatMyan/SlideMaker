#ifndef CHANGE_COMMAND_HPP
#define CHANGE_COMMAND_HPP

#include "Command.hpp"

class ChangeCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // CHANGE_COMMAND_HPP