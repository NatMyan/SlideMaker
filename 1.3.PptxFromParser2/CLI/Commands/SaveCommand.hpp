#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "SerializerCommand.hpp"

class SaveCommand : public SerializerCommand {
    public:
        void execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // SAVE_COMMAND_HPP