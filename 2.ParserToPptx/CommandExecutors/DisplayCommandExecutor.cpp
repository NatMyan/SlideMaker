#include "DisplayCommandExecutor.hpp"

#include "../definitions.hpp"

#include <iostream>

void DisplayCommandExecutor::execute (CommandType parsedCmd) {
    // if (std::get<0>(parsedCmd) == "display") {
    if (std::get<1>(parsedCmd).empty()) {
        for (const auto& item : slide_->getSlide()) {
            std::cout << "ID: " << std::get<0>(item) << " ";
            const auto shape = std::get<1>(item);
            for (const auto& mp : std::get<1>(parsedCmd)) {  
                std::cout << mp.first << " " << defs::convertToString(shape.getAttribute(mp.first)) << std::endl;
            }
            std::cout << std::endl;
        }
    }
    else if (std::get<1>(parsedCmd).find("-id") != std::get<1>(parsedCmd).end()) { 
        for (const auto& item : slide_->getSlide()) {
            int itemID = std::get<0>(item);
            int displayerID = std::get<int>(std::get<1>(parsedCmd)["-id"]);
            if (itemID == displayerID) {
                const auto shape = std::get<1>(item);
                for (const auto& mp : std::get<1>(parsedCmd)) {  
                    std::cout << mp.first << " " << defs::convertToString(shape.getAttribute(mp.first)) << std::endl;
                }
                break;
            }
        }
    }
    // }
}

