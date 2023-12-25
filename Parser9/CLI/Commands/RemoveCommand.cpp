#include "RemoveCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

#include <iostream>

namespace cli {

RemoveCommand::RemoveCommand(const Map& info) :
    infoMap_(info)
{}

void RemoveCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;

    if (isItem()) {
        ID id;
        try { id = defs::toInt(infoMap_["-id"]); }
        catch (const Exception& e) { throw InvalidIDException("ID is not a number: " + std::to_string(id)); }
        // catch (const std::out_of_range& o) { throw InvalidIDException("ID is not found"); } // assumed id exists from the isItem()
        auto slide = app->getDocument()->getSlideByItemID(id);
        if (slide) {
            auto item = slide->getItem(id);
            action = std::make_shared<RemoveItemAction>(slide, id);
        }
    }
    else if (isSlide()) {
        ID idx;
        try { idx = defs::toInt(infoMap_["-idx"]); }
        catch (const Exception& e) { idx = dir->getActiveSlideIdx(); } // shouldn't need to check if slide is nullptr or not
        auto doc = app->getDocument();
        action = std::make_shared<RemoveSlideAction>(doc, idx);
    }

    if (action) { dir->runAction(action); }
    else { throw InvalidActionException("Action is nullptr"); }
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

}