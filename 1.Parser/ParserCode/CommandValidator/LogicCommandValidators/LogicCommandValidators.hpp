#ifndef LOGIC_COMMAND_VALIDATORS_HPP
#define LOGIC_COMMAND_VALIDATORS_HPP

#include "../CommandStructureValidator.hpp"

class ANDCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class NANDCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class ORCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class NORCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class XORCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class XNORCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

class NOTCommandValiator : public CommandStructureValidator {
    public:
        bool validateCommandStructure (std::stringstream& input) override;
};

#endif // LOGIC_COMMAND_VALIDATORS_HPP