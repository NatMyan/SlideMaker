#ifndef COMMAND_VALIDATOR_HPP
#define COMMAND_VALIDATOR_HPP

#include <vector>
#include <string>

class CommandValidator {
    public:
        virtual bool validateCommand (std::stringstream& input) = 0;
};

#endif // COMMAND_VALIDATOR_HPP