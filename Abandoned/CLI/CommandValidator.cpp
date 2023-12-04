#include "CommandValidator.hpp"
#include "CommandRegistry.hpp"
#include "Exception.hpp"

bool CommandValidator::isCommandValid (const CommandType& parsedCmd) {
    return validateCommandArgNames(parsedCmd) && validateAdditionals(parsedCmd);
}

/// TODO: do separation of concerns 
bool CommandValidator::validateCommandArgNames(const CommandType& parsedCmd) const {
    CommandRegistry cmdReg;
    auto cmdTemplates = cmdReg.getCommandTemplates();

    CommandNameType cmd = "";
    try {
        cmd = cmdReg.findCommandName(parsedCmd.get<0>());
    }
    catch (const Exception&) {
        return false;
    }

    size_t ind = -1;
    for (size_t i = 0; i < cmdTemplates.size(); ++i) {
        if (cmdTemplates.at(i).commandName == cmd) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        return false;
    }

    std::vector<Key> parsedArgNames;
    for (const auto& pair : parsedCmd.get<1>()) {
        parsedArgNames.push_back(pair.first);
    }
    int matchingVecCount = 0;
    for (auto& mandatoryArgNames : cmdTemplates.at(ind).mandatoryKeys) {
        if (std::includes(parsedArgNames.begin(), parsedArgNames.end(), mandatoryArgNames.begin(), mandatoryArgNames.end())) {
            ++matchingVecCount;
        }
    }
    if (matchingVecCount != 1) {
        return false;
    }
    for (auto& mandatoryArgNames : cmdTemplates.at(ind).mandatoryKeys) {
        for (size_t i = 0; i < mandatoryArgNames.size(); ++i) {
            for (size_t j = 0; j < parsedArgNames.size(); ++j) {
                if (parsedArgNames.at(j) == mandatoryArgNames.at(i)) {
                    parsedArgNames.erase(parsedArgNames.begin() + j);
                    --j;
                }
            }
        }
    }

    matchingVecCount = 0;
    for (auto& optionalArgNames : cmdTemplates.at(ind).mandatoryKeys) {
        if (std::includes(parsedArgNames.begin(), parsedArgNames.end(), optionalArgNames.begin(), optionalArgNames.end())) {
            ++matchingVecCount;
        }
    }
    if (matchingVecCount != 1) {
        return false;
    }
    for (auto& optionalArgNames : cmdTemplates.at(ind).optionalKeys) {
        for (size_t i = 0; i < optionalArgNames.size(); ++i) {
            for (size_t j = 0; j < parsedArgNames.size(); ++j) {
                if (parsedArgNames.at(j) == optionalArgNames.at(i)) {
                    parsedArgNames.erase(parsedArgNames.begin() + j);
                    --j;
                }
            }
        }
    }
    if (!parsedArgNames.empty()) {
        return false;
    }

    return true;
}

/// TODO: finish this later
bool CommandValidator::validateAdditionals(const CommandType& parsedCmd) const {
    auto parsedCmdToModifyForCheck = parsedCmd;
    if (parsedCmdToModifyForCheck.get<0>() == "add") {
        if (parsedCmdToModifyForCheck.get<1>().find("-type") == parsedCmdToModifyForCheck.get<1>().end()) {
            return false;
        }
        else if (parsedCmdToModifyForCheck.get<1>().find("-type") != parsedCmdToModifyForCheck.get<1>().end()) {
            auto mapPCmd = parsedCmdToModifyForCheck.get<1>();
            if (mapPCmd["-type"] == defs::parseArgValue("slide")) {
                mapPCmd.erase("-type");
                if (!mapPCmd.empty()) {
                    return false;
                }
            }
        }
        return true;
    }
    return true;
}
