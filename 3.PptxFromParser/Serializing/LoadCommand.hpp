#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "SerializerCommand.hpp"

class LoadCommand : public SerializerCommand {
    public:
        void execute(CommandType parsedCmd);
};

#endif // LOAD_COMMAND_HPP