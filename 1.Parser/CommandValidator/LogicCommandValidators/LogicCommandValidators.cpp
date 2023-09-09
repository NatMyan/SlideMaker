#include "LogicCommandValidators.hpp"

bool ANDCommandValiator::validateCommandStructure (std::stringstream& input) {  
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "and" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool NANDCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "nand" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool ORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "or" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool NORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "nor" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool XORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "xor" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool XNORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "xnor" && isBinaryCommand(input)) {
        return true;
    }
    return false;
}

bool NOTCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "not" && isUnaryCommand(input)) {
        return true;
    }
    return false;
}
