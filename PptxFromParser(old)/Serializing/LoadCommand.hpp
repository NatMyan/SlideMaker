#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "SerializerCommand.hpp"

class LoadCommand : public SerializerCommand {
    public:
        void execute(CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // LOAD_COMMAND_HPP