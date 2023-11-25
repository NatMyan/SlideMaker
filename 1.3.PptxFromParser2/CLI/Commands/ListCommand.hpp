#ifndef LIST_COMMAND_EXECUTOR_HPP
#define LIST_COMMAND_EXECUTOR_HPP

#include "Command.hpp"

class ListCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // LIST_COMMAND_EXECUTOR_HPP