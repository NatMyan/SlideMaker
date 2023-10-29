#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include "Parser6.hpp"

class CommandValidator {
    public:
        bool isCommandValid (CommandType parsedCmd);
        
    private:
        bool hasPositionWidthHeight (MapPair<std::string, ArgumentType> commandPairs);
        bool hasCornerPoints (MapPair<std::string, ArgumentType> commandPairs);
        bool isNumber (ArgumentType argVal);
        bool arePositionsNumbers (MapPair<std::string, ArgumentType> commandPairs);
};

#endif // COMMAND_VALIDATOR_HPP