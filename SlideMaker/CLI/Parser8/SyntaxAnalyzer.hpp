#ifndef SYNTAX_ANALYZER_HPP
#define SYNTAX_ANALYZER_HPP

#include "../../definitions.hpp"

#include <istream>

///NOTE: separating into classes, cause I don't want to put every function into 1 class
class SyntaxAnalyzer {
    public:
        bool isSyntaxValid (CommandInfo cmdInfo);
    
    private:
        bool isValueEmpty(const Value& value);
        bool isKeyArgName(const std::string& key);
};

#endif // SYNTAX_ANALYZER_HPP