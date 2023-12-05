#include "AddCommand.hpp"

int AddCommand::itemID_ = 0;

void AddCommand::execute(Map infoMap) {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Action> action;

    if (isTypeItem(type)) {
        auto slide = Application::getDocument().getSlide(int(toNum(infoMap["-idx"])));
        auto item = std::shared_ptr<Item>();
        ++itemID_;
        action = std::make_shared<AddItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = std::shared_ptr<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }
}