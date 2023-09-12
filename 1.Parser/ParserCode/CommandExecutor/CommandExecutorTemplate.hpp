#ifndef COMMAND_EXECUTOR_TEMPLATE_HPP
#define COMMAND_EXECUTOR_TEMPLATE_HPP

#include "CommandExecutor.hpp"
#include "MathCommandExecutors.hpp"
#include "LogicCommandExecutors.hpp"
#include "OtherCommandExecutors.hpp"

#include <utility>

template <typename Operand>
Operand CommandExecutor<Operand>::executeCommandInterface (std::stringstream& input) {
    // static_cast<Operand*>(this)->executeCommand(input);  // curiously recurring template pattern (virtual, but static)
    // return executeCommand(input);
    return Operand();
}

template<typename OperandType>
OperandType computeResult (CommandExecutor<OperandType>& commandExecutor, std::stringstream& input) {
    return commandExecutor.executeCommandInterface(input);
}

#endif // COMMAND_EXECUTOR_TEMPLATE_HPP