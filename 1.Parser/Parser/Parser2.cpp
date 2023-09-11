#include "Parser2.hpp"

#include <vector>

template <typename Operand>
ParsedCommandType<Operand> Parser2<Operand>::parseCommand(std::stringstream& input) {
    std::vector<Operand> operands;
    std::string operation;
    auto tokens = tokenizeInput(input);
    if (validator.validateCommand(input) == true) {
        if (validator.isBinaryCommand(input)) {
            operands.push_back(strToOperand<Operand>(tokens.at(2)));
            operands.push_back(strToOperand<Operand>(tokens.at(4)));
        }
        else if (validator.isUnaryCommand(input)) {
            operands.push_back(strToOperand<Operand>(tokens.at(2)));
        }
        else if (validator.isMultipleOperandCommand(input)) {
            for (auto i = 2; i < tokens.size(); ++i) {
                operands.push_back(strToOperand<Operand>(tokens.at(i)));
            }
        }
    }
    /// TODO: handle null op command ?
    return {token.at(0), operands};
}

template <typename Operand>
Operand Parser2<Operand>::strToOperand (const std::string& token) {
    return Operand(token);
}