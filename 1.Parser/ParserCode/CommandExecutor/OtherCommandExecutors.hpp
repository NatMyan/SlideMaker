#ifndef OTHER_COMMAND_EXECUTOR_HPP
#define OTHER_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

class Clear : public CommandExecutor<int> {
    int executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<int>> command = this->parser.parseCommand(input);
        if (command.first == "clear") {
            std::system("clear");
        }
        return 0;
    }
};

#endif // OTHER_COMMAND_EXECUTOR_HPP