#ifndef COMMAND_VALIDATOR_FACADE_HPP
#define COMMAND_VALIDATOR_FACADE_HPP

#include "MathCommandValidators/MathCommandValidators.hpp"
#include "LogicCommandValidators/LogicCommandValidators.hpp"
#include "OtherCommandValidators/OtherCommandValidators.hpp"

#include <memory>
#include <unordered_map>

class CommandValidatorFacade : public CommandStructureValidator {
    public:
        CommandValidatorFacade();
        
    public:
        bool validateCommandStructure(std::stringstream& input) override;
        std::string extractCommand(std::stringstream& input);

    private:
        std::unordered_map<std::string, std::unique_ptr<CommandStructureValidator>> validators;
};

#endif // COMMAND_VALIDATOR_FACADE_HPP
