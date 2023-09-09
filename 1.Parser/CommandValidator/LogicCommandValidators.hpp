#ifndef LOGIC_COMMAND_VALIDATORS_HPP
#define LOGIC_COMMAND_VALIDATORS_HPP

#include "CommandValidator.hpp"

class ANDCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class NANDCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class ORCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class NORCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class XORCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class XNORCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class NOTCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

#endif // LOGIC_COMMAND_VALIDATORS_HPP