#ifndef PARSER_8_HPP
#define PARSER_8_HPP

#include "Command.hpp"
#include "Tokenizer.hpp"
#include "SyntaxAnalyzer.hpp"
#include "SemanticAnalyzer.hpp"
#include "../Commands/CommandFactory.hpp"

#include <istream>

class Parser8 {
    public:
        Parser8(std::istream& input, const char& eolToken);

    public:
        std::string createCmdString();
        CommandInfo createCommandInfo(std::istream& input, const char& endOfLineToken);
        std::shared_ptr<Command> parseCommand();
    
    private:
        bool isCmdInfoValid();
        bool fillCmdInfoMap(std::istream& input, const char& endOfLineToken, Tokenizer tokenizer);
    
    private:
        CommandInfo cmdInfo_;
        std::unique_ptr<SyntaxAnalyzer> syntaxAnalyzer_;
        std::unique_ptr<SemanticAnalyzer> semanticAnalyzer_;
        // std::unique_ptr<CommandFactory> cmdFactory_;
};

#endif // PARSER_8_HPP