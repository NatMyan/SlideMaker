#include "CommandHistory.hpp"

std::vector<std::string> CommandHistory::cmdHistory_;

void CommandHistory::append(const std::string& input) {
    cmdHistory_.push_back(input);
}