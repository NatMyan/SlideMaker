#include "ListCommandExecutor.hpp"

#include <iostream>

void ListCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "list") {
        for (const auto& item : slide_->getSlide()) {
            std::cout << "ID: " << std::get<0>(item) << std::endl;
        }
    }
}