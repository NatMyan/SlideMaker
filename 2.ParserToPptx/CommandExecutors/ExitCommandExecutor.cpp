#include "ExitCommandExecutor.hpp"

#include <stdlib.h>

void ExitCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "exit") {
        std::exit(0);
        ///TODO: remove exit, use main's return 0;
    }
}