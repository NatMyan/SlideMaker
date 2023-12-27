#include "DisplayCommand.hpp"
#include "../../Application.hpp"
#include "../../Rendering/Renderer.hpp"

namespace cli {

using Renderer = ren::Renderer;

DisplayCommand::DisplayCommand(const Map& info) :
    infoMap_(info)
{}

void DisplayCommand::execute() {
    auto app = app::Application::getApplication();
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();

    if (isItem()) {
        ID id;
        try { id = defs::toInt(infoMap_["-id"]); }
        catch (const Exception& e) { throw InvalidIDException("ID is incorrect: " + std::to_string(id)); }

        auto slide = app->getDocument()->getSlideByItemID(id);
        if (slide) {
            auto item = slide->getItem(id); // validator should make sure id is correct, so the checking should be unnecessary
            if (item) { 
                renderer->display(item, app->getController()->getOutputStream()); 
                item->accept(renderer);
            }
            else { throw InvalidItemException("Item is nullptr"); }
        }
        else { throw InvalidSlideException("Slide is nullptr"); }
    }
    else if (isSlide()) {
        ID idx;
        try { idx = defs::toInt(infoMap_["-idx"]); }
        catch (const std::exception& e) { idx = app->getDirector()->getActiveSlideIdx(); }

        auto slide = app->getDocument()->getSlide(idx); // validator should make sure id is correct, so the checking should be unnecessary
        if (slide) { 
            renderer->display(slide, app->getController()->getOutputStream()); 
            slide->getItemGroup()->accept(renderer); // What ?
        }
        else { throw InvalidSlideException("Slide is nullptr"); } 
    }
}

bool DisplayCommand::isArgFound(const std::string& argName) {
    return infoMap_.find(argName) != infoMap_.end();
}

bool DisplayCommand::isSlide() {
    return (isArgFound("-idx") || !isArgFound("-idx"))  && !isArgFound("-id"); 
}

bool DisplayCommand::isItem() {
    return isArgFound("-id") && !isArgFound("-idx");
}

}
