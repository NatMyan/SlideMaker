#include "ChangeCommand.hpp"

void ChangeCommand::execute(Map infoMap) {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Action> action;

    if (isTypeItem(type)) {
        auto slide = Application::getDocument()->getSlide(int(toNum(infoMap["-idx"])));
        auto item = slide->getItem(int(toNum(infoMap["-id"])));
        action = std::make_shared<ChangeItemAction>(slide, item, infoMap);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = doc->getSlide(int(toNum(infoMap["-idx"])));
        action = std::make_shared<ChangeSlideAction>(doc, slide, infoMap["-cidx"], infoMap["-nidx"]);
    }
}