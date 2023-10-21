#include "DisplayCommandExecutor.hpp"

#include "../definitions.hpp"

#include <iostream>

void DisplayCommandExecutor::execute (CommandType parsedCmd) {
    // if (std::get<0>(parsedCmd) == "display") {
        if (std::get<1>(parsedCmd).empty()) {
            for (const auto& item : itemStorage_) {
                std::cout << "ID: " << std::get<0>(item) << " ";
                const auto mapValue = std::get<1>(item);
                for (const auto& mp : mapValue) {  
                    std::cout << mp.first << " " << defs::convertToString(mp.second) << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else if (std::get<1>(parsedCmd).find("-id") != std::get<1>(parsedCmd).end()) { 
            for (const auto& item : itemStorage_) {
                int itemID = std::get<0>(item);
                int displayerID = std::get<int>(std::get<1>(parsedCmd)["-id"]);
                if (itemID == displayerID) {
                    const auto mapValue = std::get<1>(item);
                    for (const auto& mp : mapValue) {  
                        std::cout << mp.first << " " << defs::convertToString(mp.second) << std::endl;
                    }
                    break;
                }
            }
        }
    // }
}

