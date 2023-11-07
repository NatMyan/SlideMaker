#ifndef SERIALIZER_COMMAND_HPP
#define SERIALIZER_COMMAND_HPP

#include "../CmdLineInterface/Commands/Command.hpp"

class SerializerCommand : public Command {
    public:
        virtual void execute(CommandType parsedCmd, std::shared_ptr<Document> doc) = 0;
};

#endif // SERIALIZER_COMMAND_HPP