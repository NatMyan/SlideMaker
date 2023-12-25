#include "DisplayCommand.hpp"
#include "../../Application.hpp"
#include "../../Rendering/Renderer.hpp"

DisplayCommand::DisplayCommand(const Map& info) :
    infoMap_(info)
{}

void DisplayCommand::execute() {
    auto app = Application::getApplication();
    std::shared_ptr<Renderer> renderer = app->getRenderer(); // std::make_shared<Renderer>();

    if (isItem()) {
        auto id = defs::toInt(infoMap_["-id"]);
        auto slide = app->getDocument()->getSlideByItemID(id);
        if (slide) {
            auto item = slide->getItem(id); // validator should make sure id is correct, so the checking should be unnecessary
            if (item) { renderer->display(item, app->getCLIController()->getOutputStream()); }
        }
    }
    else if (isSlide()) {
        auto idx = defs::toInt(infoMap_["-idx"]); 
        auto slide = app->getDocument()->getSlide(idx); // validator should make sure id is correct, so the checking should be unnecessary
        if (slide) {
            renderer->display(slide, app->getCLIController()->getOutputStream());
        }
    }
}

bool DisplayCommand::isArgFound(const std::string& argName) {
    return infoMap_.find(argName) != infoMap_.end();
}

bool DisplayCommand::isSlide() {
    return isArgFound("-idx") && !isArgFound("-id");
}

bool DisplayCommand::isItem() {
    return isArgFound("-id") && !isArgFound("-idx");
}


/*
isTypeItem(type) || isTypeSlide(type) {
    auto printable = std::make_shared<IShape>(type);
    printable = dynamic_cast(IShape to ITextDisplayable);
    printable->print();
}
*/