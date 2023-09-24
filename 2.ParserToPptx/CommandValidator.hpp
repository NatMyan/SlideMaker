#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include "Parser4.hpp"

class CommandValidator {
    public:
        bool isCommandValid (std::variant<CommandType, std::string> parsedCmd);
};

#endif // COMMAND_VALIDATOR_HPP