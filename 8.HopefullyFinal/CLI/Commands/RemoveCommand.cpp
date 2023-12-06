#include "RemoveCommand.hpp"

RemoveCommand::RemoveCommand(const Map& info) :
    info_(info)
{}

void RemoveCommand::execute() {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Action> action;
    auto idx = int(toNum(infoMap["-idx"]));

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        auto item = slide->getItem(int(toNum(infoMap["-id"])));
        action = std::make_shared<RemoveItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        action = std::make_shared<RemoveSlideAction>(doc, slide);
    }
}