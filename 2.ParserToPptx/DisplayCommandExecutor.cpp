#include "DisplayCommandExecutor.hpp"

#include <iostream>

void DisplayCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "display") {
        if (std::get<2>(parsedCmd).empty()) {
            for (const auto& item : itemStorage_) {
                std::cout << "ID: " << std::get<0>(item) << " ";
                const auto mapValue = std::get<1>(item);
                for (const auto& mp : mapValue) {  
                    std::cout << mp.first << " " << convertToString(mp.second) << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else if (std::get<2>(parsedCmd).find("-id") != std::get<2>(parsedCmd).end()) { 
            for (const auto& item : itemStorage_) {
                int itemID = std::get<0>(item);
                int displayerID = std::get<int>(std::get<2>(parsedCmd)["-id"]);
                if (itemID == displayerID) {
                    const auto mapValue = std::get<1>(item);
                    for (const auto& mp : mapValue) {  
                        std::cout << mp.first << " " << convertToString(mp.second) << std::endl;
                    }
                    break;
                }
            }
        }
    }
}

std::string DisplayCommandExecutor::convertToString (ArgumentType arg) {
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