#include "SyntaxAnalyzer.hpp"

#include <iostream>

bool SyntaxAnalyzer::isSyntaxValid (CommandInfo cmdInfo) {
    return true;
    /*const auto cmdName = cmdInfo.first;
    // std::cout << "h " << cmdName << std::endl;
    const auto argMap = cmdInfo.second;
    if (!cmdName.empty()) {
        for (const auto& pair : argMap) {
            if (!isKeyArgName(pair.first)) return false;
            if (isValueEmpty(pair.second)) return false;
        }
        return true;
    }
    // std::cout << "heal my soul pls" << std::endl;
    return false;*/
}

bool SyntaxAnalyzer::isValueEmpty(const Value& value) {
    return (value != Value(std::string("")) && value != Value());
}

bool SyntaxAnalyzer::isKeyArgName(const std::string& key) {
    return (key.size() > 1) && (key.at(0) == '-');
}