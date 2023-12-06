#include "RemoveCommand.hpp"

RemoveCommand::RemoveCommand(const Map& info) :
    infoMap_(info)
{}

void RemoveCommand::execute() {
    const std::string type = toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Action> action;
    auto idx = int(toNum(infoMap_["-idx"]));

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        auto item = slide->getItem(int(toNum(infoMap_["-id"])));
        action = std::make_shared<RemoveItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        action = std::make_shared<RemoveSlideAction>(doc, slide);
    }
}