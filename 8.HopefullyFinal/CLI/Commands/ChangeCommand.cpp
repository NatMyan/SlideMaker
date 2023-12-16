#include "ChangeCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

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
        auto id = defs::toInt(infoMap_["-id"]);
        if (id > 0) {
            auto item = slide->getItem(id);
            Map necessaryInfo = createNecessaryInfo();
            action = std::make_shared<ChangeItemAction>(item, necessaryInfo);
        }
        else {
            auto itemGroup = slide->getItemGroup();
            Map necessaryInfo = createNecessaryInfo();
            action = std::make_shared<ChangeItemAction>(itemGroup, necessaryInfo);
        }
    }
    //TK: change command need to work only with items, for slides there should be another command i.e. move 
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        auto currentIndex = infoMap_["-cidx"]; 
        auto newIndex = infoMap_["-nidx"];
        action = std::make_shared<ChangeSlideAction>(doc, slide, currentIndex, newIndex);
    }

    dir->runAction(action);
}

Map ChangeCommand::createNecessaryInfo() {
    Map necessaryInfo;
    for (auto& pair : infoMap_) {
        const auto key = pair.first;
        const auto value = pair.second;
        if (key != "-idx" && key != "-id" && key != "-nidx" && key != "-cidx") {
            necessaryInfo[key] = value;
        }
    }
    return necessaryInfo;
}