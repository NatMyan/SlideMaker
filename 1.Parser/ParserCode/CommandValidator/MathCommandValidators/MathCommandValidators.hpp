#ifndef MATH_COMMAND_VALIDATORS_HPP
#define MATH_COMMAND_VALIDATORS_HPP

#include "../CommandStructureValidator.hpp"

class AddCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class SubtractCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class MultiplyCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class DivideCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class ModuloCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class PowerCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class SquareRootCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

#endif // MATH_COMMAND_VALIDATORS_HPP