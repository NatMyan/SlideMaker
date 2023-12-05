#include "DisplayCommand.hpp"

void DisplayCommand::execute(Map infoMap) {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer;
    
    if (isTypeItem(type)) {
        ///TODO: display item and its contents
        /*auto slide = Application::getDocument()->getSlide(int(toNum(infoMap["-idx"])));
        auto item = slide->getItem(int(toNum(infoMap["-idx"])));
        renderer = std::make_shared<ChangeItemAction>(slide, item, infoMap);*/
    }
    else if (isTypeSlide(type)) {
        ///TODO: display slide and its contents
        /*auto doc = Application::getDocument();
        auto slide = doc->getSlide(int(toNum(infoMap["-idx"])));
        renderer = std::make_shared<ChangeSlideAction>(doc, slide, infoMap["-cidx"], infoMap["-nidx"]);*/
    }
    else {
        ///TODO: display the entire document contents
    }
}