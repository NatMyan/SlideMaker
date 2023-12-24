#include "RemoveCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

#include <iostream>

RemoveCommand::RemoveCommand(const Map& info) :
    infoMap_(info)
{}

void RemoveCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;

    if (isItem()) {
        // std::cout << "id: " << " ]" << defs::toStr(infoMap_["-id"]) << "[" << std::endl;
        auto id = defs::toInt(infoMap_["-id"]);
        auto slide = app->getDocument()->getSlideByItemID(id);
        auto item = slide->getItem(id);
        action = std::make_shared<RemoveItemAction>(slide, id);
    }
    else if (isSlide()) {
        // std::cout << "idx: " << " ]" << defs::toStr(infoMap_["-idx"]) << "[" << std::endl;
        auto idx = defs::toInt(infoMap_["-idx"]);
        auto doc = app->getDocument();
        auto slide = doc->getSlide(idx);
        action = std::make_shared<RemoveSlideAction>(doc, idx);
    }

    dir->runAction(action);
}

bool RemoveCommand::isArgFound(const std::string& argName) {
    return infoMap_.find(argName) != infoMap_.end();
}

bool RemoveCommand::isSlide() {
    return isArgFound("-idx") && !isArgFound("-id");
}

bool RemoveCommand::isItem() {
    return isArgFound("-id") && !isArgFound("-idx");
}