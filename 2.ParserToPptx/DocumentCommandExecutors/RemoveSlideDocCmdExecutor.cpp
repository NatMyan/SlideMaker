#include "RemoveSlideDocCmdExecutor.hpp"

void RemoveSlideDocCmdExecutor::execute(CommandType parsedCmd) {
    auto temp = std::get<1>(parsedCmd);
    if (isGivenOneSlide(temp)) {
        int slideNum = std::get<int>(temp["-slideNum"]);
        doc_->getSlides().erase(doc_->getSlides().begin() + slideNum);
    }
    else if (isGivenSlideRange(temp)) {
        int slideBegin = std::get<int>(temp["-slbegin"]);
        int slideEnd = std::get<int>(temp["-slend"]);
        doc_->getSlides().erase(doc_->getSlides().begin() + slideBegin, doc_->getSlides().begin() + slideEnd);
    }
}

bool RemoveSlideDocCmdExecutor::isGivenSlideRange(std::map<std::string, ArgumentType> cmdPart) {
    return cmdPart.find("-slideNum") != cmdPart.end();
}

bool RemoveSlideDocCmdExecutor::isGivenOneSlide(std::map<std::string, ArgumentType> cmdPart) {
    return cmdPart.find("-slbegin") != cmdPart.end() && cmdPart.find("-slend") != cmdPart.end();
}