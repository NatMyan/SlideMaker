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
        
        ///TODO: implement later
        bool areValuesValid(const Map& argMap);

        bool validateAdd(const std::string& cmdName, const Map& argMap);
        bool validateRemove(const std::string& cmdName, const Map& argMap);
        bool validateChange(const std::string& cmdName, const Map& argMap);
        bool validateDraw(const std::string& cmdName, const Map& argMap);
        bool validateDisplay(const std::string& cmdName, const Map& argMap);
        bool validateSave(const std::string& cmdName, const Map& argMap);
        bool validateLoad(const std::string& cmdName, const Map& argMap);
        bool validateEmptyArgsCommands(const std::string& cmdName, const Map& argMap);
};

#endif // SEMANTIC_ANALYZER_HPP