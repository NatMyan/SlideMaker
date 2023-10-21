#include "SaveCommandExecutor.hpp"
#include "../definitions.hpp"

#include <iostream>
#include <fstream>

void SaveCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "save") {
        std::string fileWPath = std::get<std::string>(std::get<1>(parsedCmd)["-file"]);
        std::ofstream fileToSave(fileWPath);
        if (fileToSave.is_open()) {
            for (const auto& item : itemStorage_) {
                fileToSave << std::get<0>(item) << " ";
                const auto mapValue = std::get<1>(item);
                for (const auto& mp : mapValue) {  
                    fileToSave << mp.first << " " << defs::convertToString(mp.second) << std::endl;
                }
                fileToSave << std::endl;
            }
        }
        fileToSave.close();
    }
}


