#include "DrawCommand.hpp"

DrawCommand::DrawCommand(const Map& info) :
    info_(info)
{}


void DrawCommand::execute() {
    const std::string type = toStr(infoMap["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer;
    
    auto slide = Application::getDocument()->getSlide(int(toNum(infoMap["-idx"])));
    auto drawable = std::make_shared<IShape>(type);
    drawable = dynamic_cast(IShape to IVisualDisplayable);
    drawable->draw();
}

    /*if (isTypeItem(type)) {
        auto shape = ShapeFactory::createShape(type);
        ///TODO: display item and its contents
        // auto slide = Application::getDocument()->getSlide(int(toNum(infoMap["-idx"])));
        // auto item = slide->getItem(int(toNum(infoMap["-idx"])));
        // renderer = std::make_shared<ChangeItemAction>(slide, item, infoMap);
    }
    else if (isTypeSlide(type)) {
        ///TODO: display slide and its contents
        // auto doc = Application::getDocument();
        // auto slide = doc->getSlide(int(toNum(infoMap["-idx"])));
        // renderer = std::make_shared<ChangeSlideAction>(doc, slide, infoMap["-cidx"], infoMap["-nidx"]);
    }
    else {
        ///TODO: display the entire document contents
    }*/
/*
isTypeItem(type) || isTypeSlide(type) {
    auto printable = std::make_shared<IShape>(type);
    printable = dynamic_cast(IShape to ITextDisplayable);
    printable->print();
}
*/