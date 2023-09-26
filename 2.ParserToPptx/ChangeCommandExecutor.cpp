#include "ChangeCommandExecutor.hpp"

void ChangeCommandExecutor::execute(CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "change") {
        if (!std::get<2>(parsedCmd).empty()) {
            for (const auto& item : itemStorage_) {
                /*if (std::get<0>(item) == std::get<2>(parsedCmd)["-at"]) { // assuming Change -at index, index being int ...
                    changeCommand(); 
                }*/
            }
        }
    }
}

void ChangeCommandExecutor::changeCommand() {
    /// TODO: implement this 
}