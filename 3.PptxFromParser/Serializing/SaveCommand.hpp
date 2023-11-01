#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "SerializerCommand.hpp"

class SaveCommand : public SerializerCommand {
    public:
        void execute(CommandType parsedCmd);
};

#endif // SAVE_COMMAND_HPP