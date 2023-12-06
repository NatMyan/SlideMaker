#ifndef SEMANTIC_ANALYZER_HPP
#define SEMANTIC_ANALYZER_HPP

#include "../../definitions.hpp"

#include <istream>

///NOTE: separating into classes, cause I don't want to put every function into 1 class
class SemanticAnalyzer {
    public:
        bool isSemanticallyValid (CommandInfo cmdInfo);
    
    private:
        bool isCmdNameValid(const std::string& cmdName);
        bool isMandatoryArgListValid(const std::string& cmdName, const Map& argMap);
        bool isOptionalArgListValid(const std::string& cmdName, const Map& argMap);
        bool areValuesValid(const Map& argMap);
};

#endif // SEMANTIC_ANALYZER_HPP