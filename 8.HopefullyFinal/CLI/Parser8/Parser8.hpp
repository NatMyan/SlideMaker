#ifndef PARSER_8_HPP
#define PARSER_8_HPP

#include "SyntaxAnalyzer.hpp"
#include "SemanticAnalyzer.hpp"

#include <istream>

class Parser8 {
    public:
        CommandInfo constructCommandInfo(std::istream& input, const char& endOfLineToken);
        Command constructCommand();
};

#endif // PARSER_8_HPP