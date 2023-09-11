#include "CommandExecutor.hpp"

template <typename Operand>
Operand CommandExecutor<Operand>::executeCommand (std::stringstream& input) {
    static_cast<Operand*>(this)->executeCommand(input);  // curiously recurring template pattern (virtual, but static)
}

template<typename OperandType>
void computeResult (CommandExecutor<OperandType> &commandExecutor, std::stringstream& input) {
    commandExecutor.executeCommand(input);
}

// Math Commands

// Logic Commands

// Other Commands