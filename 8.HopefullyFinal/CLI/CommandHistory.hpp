#ifndef COMMAND_HISTORY_HPP
#define COMMAND_HISTORY_HPP

#include "../definitions.hpp"

#include <string>

class CommandHistory {
    public:
        void append(const std::string& input);
    
    private:
        std::vector<std::string> cmdHistory_;
};

#endif // COMMAND_HISTORY_HPP