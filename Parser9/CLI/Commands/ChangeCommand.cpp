#include "ChangeCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

ChangeCommand::ChangeCommand(const Map& info) :
    infoMap_(info)
{}

void ChangeCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;
    
    auto id = defs::toInt(infoMap_["-id"]);
    auto doc = app->getDocument();
    if (id > 0) {
        auto slide = doc->getSlideByItemID(id);
        auto item = slide->getItem(id);
        Map necessaryInfo = createNecessaryInfo();
        action = std::make_shared<ChangeItemAction>(item, necessaryInfo);
    }
    else {
        auto slide = doc->getSlide(id * (-1));
        auto itemGroup = slide->getItemGroup();
        Map necessaryInfo = createNecessaryInfo();
        action = std::make_shared<ChangeItemAction>(itemGroup, necessaryInfo);
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

