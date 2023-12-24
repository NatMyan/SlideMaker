#include "CommandHistory.hpp"

void CommandHistory::append(const std::string& input) {
    cmdHistory_.push_back(input);
}

