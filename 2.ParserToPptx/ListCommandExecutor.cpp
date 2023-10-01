#include "ListCommandExecutor.hpp"

#include <iostream>

void ListCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "list") {
        for (const auto& item : itemStorage_) {
            std::cout << "ID: " << std::get<0>(item) << std::endl;
        }
    }
}