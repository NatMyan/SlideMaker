#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include "Parser3.hpp"

class CommandValidator {
    public:
        bool isCommandValid (CommandUnderlyingType<double> parsedCmd);
};

#endif // COMMAND_VALIDATOR_HPP