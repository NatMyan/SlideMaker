#include "AddCommand.hpp"

void AddCommand::execute() {
    if (isTypeItem()) {
        auto slide = Application::getDocument().getSlide();
        auto item = std::shared_ptr<Item>();
        auto action = std::make_shared<AddItemAction>(slide, item);
    }
    else if (isTypeSlide()) {
        auto doc = Application::getDocument();
        auto slide = std::shared_ptr<Slide>();
        auto action = std::make_shared<AddSlideAction>(doc, slide);
    }
}