#include "Parser2.hpp"

#include <type_traits>
#include <vector>

template <typename Operand>
ParsedCommandType<Operand> Parser2<Operand>::parseCommand(std::stringstream& input) {
    std::vector<Operand> operands;
    std::vector<std::string> tokens = validator.tokenizeInput(input);
    if (validator.validateCommandStructure(input) == true) {
        if (validator.isBinaryCommand(input)) {
            operands.push_back(strToOperand(tokens.at(2)));
            operands.push_back(strToOperand(tokens.at(4)));
        }
        else if (validator.isUnaryCommand(input)) {
            operands.push_back(strToOperand(tokens.at(2)));
        }
        else if (validator.isMultipleOperandCommand(input)) {
            for (auto i = 2; i < tokens.size(); ++i) {
                operands.push_back(strToOperand(tokens.at(i)));
            }
        }
    }
    /// TODO: handle null op command ?
    return {tokens.at(0), operands};
}

template <typename Operand>
Operand Parser2<Operand>::strToOperand (const std::string& token) {
    if (std::is_same_v<Operand, int>) 
        return std::stoi(token);
    
    return std::stod(token);
}