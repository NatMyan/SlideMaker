#include "AddCommandExecutor.hpp"

void AddCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    if (std::get<1>(parsedCmd) == "remove") {
        int index = std::get<0>(parsedCmd);
        itemStorage_.at(index) = false;
    }
}