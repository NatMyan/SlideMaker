#include "SaveCommandExecutor.hpp"

#include <iostream>
#include <fstream>

void SaveCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "save") {
        std::string fileWPath = std::get<std::string>(std::get<2>(parsedCmd)["-file"]);
        std::ofstream fileToSave(fileWPath);
        if (fileToSave.is_open()) {
            for (const auto& item : itemStorage_) {
                fileToSave << std::get<0>(item) << " ";
                const auto mapValue = std::get<1>(item);
                for (const auto& mp : mapValue) {  
                    fileToSave << mp.first << " " << convertToString(mp.second) << std::endl;
                }
                fileToSave << std::endl;
            }
        }
        fileToSave.close();
    }
}

/// TODO: fix code duplication -> this appears in Display command
std::string SaveCommandExecutor::convertToString (ArgumentType arg) {
    struct {
        std::string operator()(const std::string& str) const {
            return str;
        }
        std::string operator()(int value) const {
            return std::to_string(value);
        }
        std::string operator()(double value) const {
            return std::to_string(value);
        }
    } visitor;

    return std::visit(visitor, arg);
}

