#include "AddCommand.hpp"

int AddCommand::itemID_ = 0;

AddCommand::AddCommand(const Map& info) :
    info_(info)
{}

void AddCommand::execute() {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Action> action;

    if (isTypeItem(type)) {
        auto idx = int(toNum(infoMap["-idx"]));
        auto slide = Application::getDocument().getSlide(idx);
        auto item = std::shared_ptr<Item>(argumenteghen from infoMap, ++itemID_);
        action = std::make_shared<AddItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = std::shared_ptr<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }
}