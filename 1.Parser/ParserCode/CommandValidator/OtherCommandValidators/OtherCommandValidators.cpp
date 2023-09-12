#include "OtherCommandValidators.hpp"

bool ClearCommandValidator::validateCommandStructure (std::stringstream& input) {
    auto tokens = tokenizeInput(input);    
    if (tokens.at(0) == "clear" && isNullOperandCommand(input)) {
        return true;
    }
    return false;
}