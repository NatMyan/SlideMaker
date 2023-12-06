#include "ChangeCommand.hpp"

ChangeCommand::ChangeCommand(const Map& info) :
    info_(info)
{}

void ChangeCommand::execute() {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Action> action;
    auto idx = int(toNum(infoMap["-idx"]));

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        auto item = slide->getItem(int(toNum(infoMap["-id"])));
        action = std::make_shared<ChangeItemAction>(slide, item, infoMap);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(idx);
        action = std::make_shared<ChangeSlideAction>(doc, slide, infoMap["-cidx"], infoMap["-nidx"]);
    }
}