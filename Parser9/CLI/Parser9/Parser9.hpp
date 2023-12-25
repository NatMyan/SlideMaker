#ifndef PARSER_9_HPP
#define PARSER_9_HPP

#include "../Commands/Command.hpp"
#include "Tokenizer.hpp"
#include "SyntaxAnalyzer.hpp"
#include "SemanticAnalyzer.hpp"
#include "../CommandFactory.hpp"

#include <istream>

namespace cli {

class Parser9 {
    public:
        Parser9(std::shared_ptr<CommandFactory> cmdFactory, std::istream& input, const char& eolToken);

    public:
        std::string createCmdString();
        CommandInfo createCommandInfo(std::istream& input, const char& endOfLineToken);
        std::shared_ptr<Command> parseCommand();
    
    private:
        bool isCmdInfoValid();
        // bool fillCmdInfoMap(std::istream& input, const char& endOfLineToken, Tokenizer tokenizer);
    
    private:
        CommandInfo cmdInfo_;
        std::unique_ptr<SyntaxAnalyzer> syntaxAnalyzer_;
        std::unique_ptr<SemanticAnalyzer> semanticAnalyzer_;
        std::shared_ptr<CommandFactory> cmdFactory_;
};

}

#endif // PARSER_9_HPP