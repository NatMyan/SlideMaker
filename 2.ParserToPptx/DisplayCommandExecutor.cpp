#include "DisplayCommandExecutor.hpp"

#include <iostream>

void DisplayCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "display") {
        for (const auto& item : itemStorage_) {
            std::cout << "ID: " << std::get<0>(item) << " ";
            if (std::is_same_v <decltype(std::get<1>(item)), std::map<std::string, ArgumentType> >) {
                for (const auto& pair : std::get<1>(item)) {  // what ?
                    std::cout << pair.first << " " << pair.second << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
}