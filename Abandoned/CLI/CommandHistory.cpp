#include "CommandHistory.hpp"

CommandHistoryContainer CommandHistory::cmdHistory;

void CommandHistory::append(const std::string& input) {
    cmdHistory.push_back(input);
}