#include "MathCommandValidators.hpp"


bool AddCommandValiator::validateCommandStructure (std::stringstream& input) {  
    /*std::stringstream ssInput;
    ssInput << input.rdbuf();*/
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "add" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool SubtractCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "sub" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool MultiplyCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "mul" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool DivideCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "div" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool ModuloCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "mod" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool PowerCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "pow" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool SquareRootCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "sqrt" && isUnaryCommand(input)) {
        return true;
    }
    return false;
}
