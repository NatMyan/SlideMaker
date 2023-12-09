#include "DisplayCommand.hpp"
#include "../../Application.hpp"
#include "../../Rendering/Renderer.hpp"

DisplayCommand::DisplayCommand(const Map& info) :
    infoMap_(info)
{}

void DisplayCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer = Application::getRenderer(); // std::make_shared<Renderer>();
    auto renderer = Application::getRenderer();
    auto idx = defs::toInt(infoMap_["-idx"]);

    if (isTypeItem(type)) {
        auto id = defs::toInt(infoMap_["-id"]);
        auto item = Application::getDocument()->getSlide(idx)->getItem(id);
        renderer->display(item, *Application::getOutputStream());
    }
    else if (isTypeSlide(type)) {
        auto slide = Application::getDocument()->getSlide(idx);
        auto group = slide->getItemGroup();
        renderer->display(group, *Application::getOutputStream());
    }
    // else {
        ///TODO: display the entire document contents
    // }
}

/*
isTypeItem(type) || isTypeSlide(type) {
    auto printable = std::make_shared<IShape>(type);
    printable = dynamic_cast(IShape to ITextDisplayable);
    printable->print();
}
*/