#include "ExitCommandExecutor.hpp"

#include <stdlib.h>

void ExitCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "exit") {
        std::exit(0);
    }
}