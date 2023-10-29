#include "ChangeCommandExecutor.hpp"

#include <map>

void ChangeCommandExecutor::execute(CommandType parsedCmd) {  // that's a lotta brackets
    // if (std::get<0>(parsedCmd) == "change") {
        if (!std::get<1>(parsedCmd).empty()) {
            for (auto& item : slide_->getSlide()) {
                int itemID = std::get<0>(item);
                int changerID = std::get<int>(std::get<1>(parsedCmd)["-id"]);
                if (itemID == changerID) {
                    for (auto& arg : std::get<1>(parsedCmd)) {
                        if (arg.first != "-id") {
                            auto shape = std::get<1>(item);
                            shape.setAttribute(arg.first, arg.second);
                        }
                    }
                }
            }
        }
    // }
}
