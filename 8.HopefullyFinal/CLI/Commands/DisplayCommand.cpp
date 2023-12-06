#include "DisplayCommand.hpp"

DisplayCommand::DisplayCommand(const Map& info) :
    infoMap_(info)
{}

void DisplayCommand::execute() {
    const std::string type = toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();
    auto renderer = Application::getRenderer();
    auto idx = int(toNum(infoMap_["-idx"]));
    auto id = int(toNum(infoMap_["-id"]));

    if (isTypeItem(type)) {
        auto item = Application::getDocument()->getSlide(idx)->getItem(id);
        renderer->print(item);
    }
    else if (isTypeSlide(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        renderer->print(slide);
    }
    else {
        ///TODO: display the entire document contents
    }
}

/*
isTypeItem(type) || isTypeSlide(type) {
    auto printable = std::make_shared<IShape>(type);
    printable = dynamic_cast(IShape to ITextDisplayable);
    printable->print();
}
*/