#ifndef PARSER_8_HPP
#define PARSER_8_HPP

#include "Command.hpp"
#include "SyntaxAnalyzer.hpp"
#include "SemanticAnalyzer.hpp"

#include <istream>

class Parser8 {
    public:
        Parser8();

    public:
        CommandInfo constructCommandInfo(std::istream& input, const char& endOfLineToken);
        std::shared_ptr<Command> constructCommand();
    
    private:
        bool isCmdInfoValid();
    
    private:
        CommandInfo cmdInfo_;
        std::unique_ptr<SyntaxAnalyzer> syntaxAnalyzer_;
        std::unique_ptr<SemanticAnalyzer> semanticAnalyzer_;
};

#endif // PARSER_8_HPP