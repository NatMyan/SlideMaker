#include "RemoveCommandExecutor.hpp"

void RemoveCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    if (std::get<1>(parsedCmd) == "remove") {
        int index = std::get<0>(parsedCmd);
        std::get<1>(itemStorage_.at(index)) = false; 
        /// TODO: clear and delete, or false ?
    }
}