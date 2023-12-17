#include "RemoveCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

RemoveCommand::RemoveCommand(const Map& info) :
    infoMap_(info)
{}

void RemoveCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;
    auto idx = defs::toInt(infoMap_["-idx"]);

    if (isTypeItem(type)) {
        auto id = defs::toInt(infoMap_["-id"]);
        auto slide = app->getDocument()->getSlide(idx);
        auto item = slide->getItem(id);
        action = std::make_shared<RemoveItemAction>(slide, id);
    }
    else if (isTypeSlide(type)) {
        auto doc = app->getDocument();
        auto slide = doc->getSlide(idx);
        action = std::make_shared<RemoveSlideAction>(doc, idx);
    }

    dir->runAction(action);
}