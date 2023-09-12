#include "MathCommandValidators.hpp"


bool AddCommandValiator::validateCommandStructure (std::stringstream& input) {  
    /*std::stringstream ssInput;
    ssInput << input.rdbuf();*/
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "add" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool SubtractCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "sub" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool MultiplyCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "mul" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool DivideCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);   
    std::string zero = "0"; 
    if (tokens.at(0) == "div") {
        if (isBinaryCommand(input)) 
            if (!(tokens.at(4) == zero)) 
                return true;
        else if (isMultipleOperandCommand(input)) 
            for (int i = 3; i < tokens.size(); ++i) 
                if (tokens.at(i) == zero) 
                    return false;
            return true;
    }
    return false;
}

bool ModuloCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "mod" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool PowerCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "pow" && (isBinaryCommand(input) || isMultipleOperandCommand(input))) {
        return true;
    }
    return false;
}

bool SquareRootCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "sqrt" && isUnaryCommand(input)) {
        return true;
    }
    return false;
}
