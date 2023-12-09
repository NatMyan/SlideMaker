#ifndef COMMAND_FACTORYY_HPP
#define COMMAND_FACTORYY_HPP

#include "../../definitions.hpp"

#include <functional>
#include <memory>
#include <string>

class CommandFactory {
    public:
        CommandFactory(const CommandInfo& cmdInfo);
        std::unique_ptr<Command> createCommand();
    
    private:
        CommandInfo cmdInfo_;
        // std::unordered_map<std::string, std::function<std::unique_ptr<Command>(Map)> > commandMap_;
};

#endif // COMMAND_FACTORYY_HPP