#include "ChangeCommandExecutor.hpp"

void ChangeCommandExecutor::execute(CommandType parsedCmd) {  // that's a lotta brackets
    if (std::get<1>(parsedCmd) == "change") {
        if (!std::get<2>(parsedCmd).empty()) {
            for (const auto& item : itemStorage_) {
                int itemID = std::get<0>(item);
                int changerID = std::get<int>(std::get<2>(parsedCmd)["-id"]);
                if (itemID == changerID) { // assuming Change -id index, index being int ...
                    for (auto& arg : std::get<2>(parsedCmd)) {
                        if (arg.first != "-id") {
                            std::get<2>(item)[arg.first] = arg.second;
                        }
                    }
                }
            }
        }
    }
}
