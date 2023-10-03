#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include "Parser4.hpp"

class CommandValidator {
    public:
        bool isCommandValid (CommandType parsedCmd);
    private:
        bool hasPositionWidthHeight (std::map<std::string, ArgumentType> commandPairs);
        bool hasCornerPoints (std::map<std::string, ArgumentType> commandPairs);
        bool isNumber (ArgumentType argVal);
        bool arePositionsNumbers (std::map<std::string, ArgumentType> commandPairs);
};

#endif // COMMAND_VALIDATOR_HPP