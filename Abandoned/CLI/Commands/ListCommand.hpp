#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "Command.hpp"

class ListCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // LIST_COMMAND_HPP