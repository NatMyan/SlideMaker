#include "ChangeCommandExecutor.hpp"

#include <map>

void ChangeCommandExecutor::execute(CommandType parsedCmd) {  // that's a lotta brackets
    if (std::get<1>(parsedCmd) == "change") {
        if (!std::get<2>(parsedCmd).empty()) {
            for (auto& item : itemStorage_) {
                int itemID = std::get<0>(item);
                int changerID = std::get<int>(std::get<2>(parsedCmd)["-id"]);
                if (itemID == changerID) {
                    for (auto& arg : std::get<2>(parsedCmd)) {
                        if (arg.first != "-id") {
                            std::get<1>(item)[arg.first] = arg.second;
                        }
                    }
                }
            }
        }
    }
}
