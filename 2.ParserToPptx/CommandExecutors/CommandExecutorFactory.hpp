#ifndef COMMAND_EXECUTOR_FACTORY_HPP
#define COMMAND_EXECUTOR_FACTORY_HPP

#include "CommandExecutor.hpp"
#include "AddCommandExecutor.hpp"
#include "ChangeCommandExecutor.hpp"
#include "DisplayCommandExecutor.hpp"
#include "RemoveCommandExecutor.hpp"
#include "ListCommandExecutor.hpp"
#include "ExitCommandExecutor.hpp"
#include "SaveCommandExecutor.hpp"
#include "LoadCommandExecutor.hpp"

// #include "../DocumentCommandExecutors/DocumentCommandExecutor.hpp"
// #include "../DocumentCommandExecutors/AddSlideCommandExecutor.hpp"

class CommandExecutorFactory {
    public:
        std::unique_ptr<CommandExecutor> createCommandExecutor (const std::string& cmdName);
        ///TODO: static or not?

    private:
        std::string convertToString (ArgumentType arg);
};

#endif // COMMAND_EXECUTOR_FACTORY_HPP