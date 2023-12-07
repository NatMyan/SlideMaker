#include "ChangeCommand.hpp"

ChangeCommand::ChangeCommand(const Map& info) :
    infoMap__(info)
{}

void ChangeCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Action> action;
    auto idx = defs::toInt(infoMap_["-idx"]);

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        auto item = slide->getItem(defs::toInt(infoMap_["-id"]));
        action = std::make_shared<ChangeItemAction>(slide, item, infoMap_);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        auto currentIndex = infoMap_["-cidx"];
        auto newIndex = infoMap_["-nidx"];
        action = std::make_shared<ChangeSlideAction>(doc, slide, currentIndex, newIndex);
    }
}