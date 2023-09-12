#include "CommandValidatorFacade.hpp"

#include <iostream>

CommandValidatorFacade::CommandValidatorFacade() {               // I've tried decoupling
    validators["add"] = std::make_unique<AddCommandValiator>();
    validators["sub"] = std::make_unique<SubtractCommandValiator>();
    validators["mul"] = std::make_unique<MultiplyCommandValiator>();
    validators["div"] = std::make_unique<DivideCommandValiator>();
    validators["mod"] = std::make_unique<ModuloCommandValiator>();
    validators["pow"] = std::make_unique<PowerCommandValiator>();
    validators["sqrt"] = std::make_unique<SquareRootCommandValiator>();
    validators["and"] = std::make_unique<ANDCommandValiator>();
    validators["nand"] = std::make_unique<NANDCommandValiator>();
    validators["or"] = std::make_unique<ORCommandValiator>();
    validators["nor"] = std::make_unique<NORCommandValiator>();
    validators["xor"] = std::make_unique<XORCommandValiator>();
    validators["xnor"] = std::make_unique<XNORCommandValiator>();
    validators["not"] = std::make_unique<NOTCommandValiator>();
    validators["clear"] = std::make_unique<ClearCommandValidator>();
}

bool CommandValidatorFacade::validateCommandStructure(std::stringstream& input) {
    std::string commandName;
    
        commandName = extractCommand(input);
    
    try {
        auto it = validators.find(commandName);
        if (it != validators.end() && it->second) {
            return it->second->validateCommandStructure(input);
        }
    } 
    catch (const std::bad_alloc& e) {
        std::cout << "help" << std::endl;
    }
    
    return false;
}

std::string CommandValidatorFacade::extractCommand(std::stringstream& input) {
    auto tokens = tokenizeInput(input);
    return tokens.at(0);
}
