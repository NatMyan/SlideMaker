#include "CommandExecutor.hpp"

#include <cmath>

double CommandExecutor::executeCommand (CommandUnderlyingType<double> parsedCmd) { // bad code, yikes
    const std::string& commandName = parsedCmd.first;
    const std::map<std::string, std::vector<double>>& commandData = parsedCmd.second;
    if (commandName.find("add") != std::string::npos) {
        if (!commandData.empty()) {
        double add = 0.0;
        for (const auto& pair : commandData) {
            for (double value : pair.second) {
                add += value;
            }
        }
        return add;
        }
    }
    else if (commandName.find("sub") != std::string::npos) {
        if (!commandData.empty()) {
            double sub = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    sub -= pair.second.at(i); 
                }
            }
            return sub;
        }
    }
    else if (commandName.find("mul") != std::string::npos) {
        if (!commandData.empty()) {
        double mul = 1.0;
        for (const auto& pair : commandData) {
            for (double value : pair.second) {
                mul *= value;
            }
        }
        return mul;
        }
    } 
    else if (commandName.find("div") != std::string::npos) {
        if (!commandData.empty()) {
            double div = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    div /= pair.second.at(i); 
                }
            }
            return div;
        }
    }  
    else if (commandName.find("mod") != std::string::npos) {
        if (!commandData.empty()) {
            int mod = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    mod %= static_cast<int>(pair.second.at(i)); 
                }
            }
            return mod;
        }
    }
    else if (commandName.find("pow") != std::string::npos) {
        if (!commandData.empty()) {
            int powRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    powRes = std::pow(powRes, pair.second.at(i)); 
                }
            }
            return powRes;
        }
    }
    else if (commandName.find("sqrt") != std::string::npos) {
        if (!commandData.empty()) {
            double sqr = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    sqr = std::sqrt(pair.second.at(i)); 
                }
            }
            return sqr;
        }
    }

    else if (commandName.find("and") != std::string::npos) {
        if (!commandData.empty()) {
            int andRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    andRes = andRes & static_cast<int>(pair.second.at(i)); 
                }
            }
            return andRes;
        }
    }
    else if (commandName.find("nand") != std::string::npos) {
        if (!commandData.empty()) {
            int nandRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    nandRes = !(nandRes & static_cast<int>(pair.second.at(i))); 
                }
            }
            return nandRes;
        }
    }
    else if (commandName.find("or") != std::string::npos) {
        if (!commandData.empty()) {
            int orRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    orRes = orRes | static_cast<int>(pair.second.at(i)); 
                }
            }
            return orRes;
        }
    }
    else if (commandName.find("nor") != std::string::npos) {
        if (!commandData.empty()) {
            int norRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    norRes = !(norRes | static_cast<int>(pair.second.at(i))); 
                }
            }
            return norRes;
        }
    }
    else if (commandName.find("xor") != std::string::npos) {
        if (!commandData.empty()) {
            int xorRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    xorRes = xorRes ^ static_cast<int>(pair.second.at(i)); 
                }
            }
            return xorRes;
        }
    }
    else if (commandName.find("xnor") != std::string::npos) {
        if (!commandData.empty()) {
            int xnorRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    xnorRes = !(xnorRes ^ static_cast<int>(pair.second.at(i))); 
                }
            }
            return xnorRes;
        }
    }
    else if (commandName.find("not") != std::string::npos) {
        if (!commandData.empty()) {
            int notRes = commandData.begin()->second.front(); 
            for (const auto& pair : commandData) {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    notRes = !static_cast<int>(pair.second.at(i)); 
                }
            }
            return notRes;
        }
    }
    else if (commandName.find("clear") != std::string::npos) {
        system("cls"); 
        return std::numeric_limits<double>::quiet_NaN();
    }
    return std::numeric_limits<double>::quiet_NaN();
}