#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Parser2.hpp"

template <typename Operand>
class CommandExecutor {
    public:
        CommandExecutor (const Parser2& commandParser) : parser {commandParser} {}
    
    public: 
        Operand executeCommand (std::stringstream& input); 
    
    private:
        Parser2 parser;
};

#endif // COMMAND_EXECUTOR_HPP

