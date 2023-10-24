#include "SaveCommandExecutor.hpp"
#include "../definitions.hpp"

#include <iostream>
#include <fstream>

void SaveCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "save") {
        std::string fileWPath = std::get<std::string>(std::get<1>(parsedCmd)["-file"]);
        std::ofstream fileToSave(fileWPath);
        if (fileToSave.is_open()) {
            for (const auto& item : slide_->getSlide()) {
                fileToSave << std::get<0>(item) << " ";
                auto shape = std::get<1>(item);
                for (const auto& mp : std::get<1>(parsedCmd)) {  
                    fileToSave << mp.first << " " << defs::convertToString(shape.getAttribute(mp.first)) << std::endl;
                }
                fileToSave << std::endl;
            }
        }
        fileToSave.close();
    }
}




