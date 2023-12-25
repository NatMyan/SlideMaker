#include "ChangeCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

namespace cli {

ChangeCommand::ChangeCommand(const Map& info) :
    infoMap_(info)
{}

void ChangeCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    auto doc = app->getDocument();
    std::shared_ptr<IAction> action = nullptr;
    Map necessaryInfo = createNecessaryInfo();
    
    ID id;
    try { id = defs::toInt(infoMap_["-id"]); }
    catch (const Exception& e) { throw InvalidIDException("ID is incorrect" + std::to_string(id)); }

    if (id > 0) {
        auto slide = doc->getSlideByItemID(id);
        auto item = slide->getItem(id);
        action = std::make_shared<ChangeItemAction>(item, necessaryInfo);
    }
    else {
        auto slide = doc->getSlide(id * (-1));
        auto itemGroup = slide->getItemGroup();
        action = std::make_shared<ChangeItemAction>(itemGroup, necessaryInfo);
    }
    
    if (action) { dir->runAction(action); }
    else { throw InvalidActionException("Action is nullptr"); }
}

Map ChangeCommand::createNecessaryInfo() {
    Map necessaryInfo;
    for (auto& pair : infoMap_) {
        const auto key = pair.first;
        const auto value = pair.second;
        if (key != "-id") {
            necessaryInfo[key] = value;
        }
    }
    return necessaryInfo;
}

}