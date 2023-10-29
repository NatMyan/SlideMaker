#include "AddSlideDocCmdExecutor.hpp"

void AddSlideDocCmdExecutor::execute(CommandType parsedCmd) {
    // if (std::get<1>(parsedCmd)["-type"] == "slide") 
    doc_->getSlides().push_back(Slide{});
}