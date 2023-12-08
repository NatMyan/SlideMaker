#include "ChangeCommand.hpp"

ChangeCommand::ChangeCommand(const Map& info) :
    infoMap_(info)
{}

void ChangeCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    auto dir = Application::getDirector();
    std::shared_ptr<IAction> action = nullptr;
    auto idx = defs::toInt(infoMap_["-idx"]);

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        if (infoMap_["-type"] == Value(std::string("item"))) {
            auto id = defs::toInt(infoMap_["-id"]);
            auto item = slide->getItem(id);
            action = std::make_shared<ChangeItemAction>(item, infoMap_);
        }
        else if (infoMap_["-type"] == Value(std::string("item"))) {
            auto itemGroup = slide->getTopItem();
            action = std::make_shared<ChangeItemAction>(itemGroup, infoMap_);
        }
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        auto currentIndex = infoMap_["-cidx"]; 
        auto newIndex = infoMap_["-nidx"];
        action = std::make_shared<ChangeSlideAction>(doc, currentIndex, newIndex);
    }

    dir->runAction(action);
}