#ifndef LIST_COMMAND_EXECUTOR_HPP
#define LIST_COMMAND_EXECUTOR_HPP

#include "RendererCommand.hpp"

class ListCommand : public RendererCommand {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // LIST_COMMAND_EXECUTOR_HPP