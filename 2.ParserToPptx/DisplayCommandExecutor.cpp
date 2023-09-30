#include "DisplayCommandExecutor.hpp"

#include <iostream>

void DisplayCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "display") {
        for (const auto& item : itemStorage_) {
            std::cout << "ID: " << std::get<0>(item) << " ";
            // if constexpr (std::is_same_v <decltype(std::get<1>(item)), std::map<std::string, ArgumentType> >) {
                const auto mapValue = std::get<1>(item);
                for (const auto& mp : mapValue) {  // what ?
                    std::cout << mp.first << " " << convertToString(mp.second) << std::endl;
                }
                std::cout << std::endl;
           //  }
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