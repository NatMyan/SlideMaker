#ifndef SEMANTIC_ANALYZER_HPP
#define SEMANTIC_ANALYZER_HPP

#include "../../definitions.hpp"

#include <istream>

///NOTE: separating into classes, cause I don't want to put every function into 1 class
class SemanticAnalyzer {
    public:
        bool isSemanticallyValid (CommandInfo cmdInfo);
};

#endif // SEMANTIC_ANALYZER_HPP