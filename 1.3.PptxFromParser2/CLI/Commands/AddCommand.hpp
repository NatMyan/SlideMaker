#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "Command.hpp"

class AddCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // ADD_COMMAND_HPP