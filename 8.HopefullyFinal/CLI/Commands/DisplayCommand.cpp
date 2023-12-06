#include "DisplayCommand.hpp"

DisplayCommand::DisplayCommand(const Map& info) :
    info_(info)
{}

void DisplayCommand::execute() {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();
    auto renderer = Application::getRenderer();

    if (isTypeItem(type)) {
        ///TODO: display item and its contents
        auto item = Application::getDocument()->getSlide(slideindex)->getItem(itemid);
        renderer->print(item);
    }
    else if (isTypeSlide(type)) {
        ///TODO: display slide and its contents
        auto slide = Application::getDocument()->getSlide(slideIndex or currentslide);
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