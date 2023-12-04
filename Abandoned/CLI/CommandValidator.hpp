#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include "../definitions.hpp"

class CommandValidator {
    public:
        bool isCommandValid (const CommandType& parsedCmd);
    
    private:
        bool validateCommandArgNames(const CommandType& parsedCmd) const;
        bool validateAdditionals(const CommandType& parsedCmd) const;
};

#endif // COMMAND_VALIDATOR_HPP