#include "ExitCommandExecutor.hpp"

#include <stdlib.h>

void ExitCommandExecutor::execute (CommandType parsedCmd) {
    // if (std::get<0>(parsedCmd) == "exit") {
        isExit_ = true;
        ///TODO: remove exit, use main's return 0;
    // }
}

bool ExitCommandExecutor::getExitVal() {
    return isExit_;
}