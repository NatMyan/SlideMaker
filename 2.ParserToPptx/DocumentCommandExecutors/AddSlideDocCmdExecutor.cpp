#include "AddSlideDocCmdExecutor.hpp"

void AddSlideDocCmdExecutor::execute(CommandType parsedCmd) {
    // if (std::get<1>(parsedCmd)["-type"] == "slide") 
        slides_.push_back(Slide{});
}