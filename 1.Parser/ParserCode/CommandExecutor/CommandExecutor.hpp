#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "../Parser/Parser2.hpp"
/*
template <typename Operand>
class CommandExecutor {
    public:
        CommandExecutor (Parser2<Operand>& commandParser) : parser {commandParser} {}

    public:
        virtual Operand executeCommand(std::stringstream& input) = 0;

    protected:
        Parser2<Operand> parser;
};
*/


template <typename Operand>
class CommandExecutor {
    public:
        CommandExecutor (Parser2<Operand>& commandParser) : parser {commandParser} {}
    
    public: 
        Operand executeCommandInterface (std::stringstream& input); 
    
    protected:
        Parser2<Operand> parser;
};

#endif // COMMAND_EXECUTOR_HPP

