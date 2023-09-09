#ifndef MATH_COMMAND_VALIDATORS_HPP
#define MATH_COMMAND_VALIDATORS_HPP

#include "CommandValidator.hpp"

class AddCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class SubtractCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class MultiplyCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class DivideCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class ModuloCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class PowerCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};

class SquareRootCommandValiator : public CommandValidator {
    public:
        bool validateCommand (std::stringstream& input) override;
};
#endif // MATH_COMMAND_VALIDATORS_HPP