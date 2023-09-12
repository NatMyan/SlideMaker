#include "LogicCommandValidators.hpp"

bool ANDCommandValiator::validateCommandStructure (std::stringstream& input) {  
    auto tokens = tokenizeInput(input);    
    if (tokens[0] == "and" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1"))  {
        return true;
    }
    return false;
}

bool NANDCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "nand" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1")) {
        return true;
    }
    return false;
}

bool ORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "or" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1")) {
        return true;
    }
    return false;
}

bool NORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "nor" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1"))  {
        return true;
    }
    return false;
}

bool XORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "xor" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1"))  {
        return true;
    }
    return false;
}

bool XNORCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "xnor" && isBinaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1")) {
        return true;
    }
    return false;
}

bool NOTCommandValiator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "not" && isUnaryCommand(input)
        && (tokens.at(2) == "0" || tokens.at(2) == "1") 
        && (tokens.at(4) == "0" || tokens.at(4) == "1")) {
        return true;
    }
    return false;
}
