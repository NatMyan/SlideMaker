#ifndef OTHER_COMMAND_VALIDATORS_HPP
#define OTHER_COMMAND_VALIDATORS_HPP

#include "../CommandStructureValidator.hpp"

class ClearCommandValidator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};


#endif // OTHER_COMMAND_VALIDATORS_HPP