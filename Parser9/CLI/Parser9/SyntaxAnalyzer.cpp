#include "SyntaxAnalyzer.hpp"

#include <iostream>

namespace cli {

bool SyntaxAnalyzer::isSyntaxValid (CommandInfo cmdInfo) {
    const auto cmdName = cmdInfo.first;
    const auto argMap = cmdInfo.second;
    
    if (!cmdName.empty()) {
        for (const auto& pair : argMap) {
            if (!isKeyArgName(pair.first)) return false;
            if (isValueEmpty(pair.second)) return false;
        }
        return true;
    }
    
    return false;
}

bool SyntaxAnalyzer::isValueEmpty(const Value& value) {
    return (value != Value(std::string("")) && value != Value());
}

bool SyntaxAnalyzer::isKeyArgName(const std::string& key) {
    return (key.size() > 1) && (key.at(0) == '-');
}

}