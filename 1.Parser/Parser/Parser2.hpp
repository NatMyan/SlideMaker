#ifndef PARSER2_HPP
#define PARSER2_HPP

#include "CommandValidatorFacade.hpp"

#include <utility>

template <typename Operand>
using ParsedCommandType = std::pair<std::string, std::vector<Operand>>;

template <typename Operand>
class Parser2 {
    public:
        Parser2(const CommandValidatorFacade& validatorFacade) : validator(validatorFacade) {}
        
    public:
        ParsedCommandType<Operand> parseCommand(std::stringstream& input);

    private:
        Operand strToOperand (const std::string& token);

    private:
        CommandValidatorFacade& validator;
};

#endif // PARSER2_HPP