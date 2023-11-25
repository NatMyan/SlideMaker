#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "Command.hpp"

class LoadCommand : public Command {
    public:
        void execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // LOAD_COMMAND_HPP