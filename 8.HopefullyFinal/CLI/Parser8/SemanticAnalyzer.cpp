#include "SemanticAnalyzer.hpp"
#include "CommandRegistry.hpp"
#include "Exception.hpp"

#include <algorithm>

///TODO: are values valid -> implement

bool SemanticAnalyzer::isSemanticallyValid (CommandInfo cmdInfo) {
    const auto cmdName = cmdInfo.first;
    const auto argMap = cmdInfo.second;
    if (isCmdNameValid(cmdName) && isMandatoryArgListValid(cmdName, argMap) && 
        isOptionalArgListValid(cmdName, argMap) && areValuesValid(argMap))
        return true;
    return false;
}

bool SemanticAnalyzer::isCmdNameValid(const std::string& cmdName) {
    CommandRegistry cmdReg;
    try { 
        cmdReg.findCommandName(cmdName); 
    } 
    catch (const Exception& e) { 
        return false; 
    }
    return true;
}

bool SemanticAnalyzer::isMandatoryArgListValid(const std::string& cmdName, const Map& argMap) {
    CommandRegistry cmdReg;
    auto it = cmdReg.findCmdIter(cmdName);
    if (it != cmdReg.getCommandTemplates().end()) {
        const auto& mandatoryLists = it->mandatoryKeys;
        for (const auto& mandatorySet : mandatoryLists) {
            bool allKeysPresent = true;
            for (const auto& key : mandatorySet) {
                if (argMap.find(key) == argMap.end()) {
                    allKeysPresent = false;
                    break;
                }
            }
            if (allKeysPresent) {
                return true;
            }
        }
        return false;
    }
    return false;
}

bool SemanticAnalyzer::isOptionalArgListValid(const std::string& cmdName, const Map& argMap) {
    CommandRegistry cmdReg;
    auto it = cmdReg.findCmdIter(cmdName);
    if (it != cmdReg.getCommandTemplates().end()) {
        const auto& optionalLists = it->optionalKeys;
        for (const auto& optionalSet : optionalLists) {
            for (const auto& entry : argMap) {
                const auto& key = entry.first;
                if (std::find(optionalSet.begin(), optionalSet.end(), key) == std::end(optionalSet)) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}



