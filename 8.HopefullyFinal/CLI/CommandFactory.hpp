#ifndef COMMAND_FACTORYY_HPP
#define COMMAND_FACTORYY_HPP

#include "../definitions.hpp"
#include "Commands/Command.hpp"

#include <functional>
#include <memory>
#include <string>

class CommandFactory {
    public:
        std::unique_ptr<Command> createCommand(const CommandInfo& cmdInfo);
};

#endif // COMMAND_FACTORYY_HPP