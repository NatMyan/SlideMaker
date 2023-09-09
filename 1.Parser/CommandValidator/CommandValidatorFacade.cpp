#include "CommandValidatorFacade.hpp"

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

bool CommandValidatorFacade::validateCommand(std::stringstream& input) {
    std::string commandName = extractCommand(input);
    auto it = validators.find(commandName);
    if (it != validators.end()) {
        return it->second->validateCommandStructure(input);
    }
    return false;
}

