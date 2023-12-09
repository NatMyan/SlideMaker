#include "DrawCommand.hpp"
#include "../../Application.hpp"

#include <QPainter>

DrawCommand::DrawCommand(const Map& info) :
    infoMap_(info)
{}

void DrawCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();
    auto idx = defs::toInt(infoMap_["-idx"]);
    auto filePath = defs::toStr(infoMap_["-file"]);
    auto slide = Application::getDocument()->getSlide(idx);
    auto [width, height] = calculateImgDocWidthHeight();
    QImage img(width, height, QImage::Format_ARGB32);
    renderer->draw(slide, &img);
    img.save(filePath.c_str()); // Assuming filePath is a std::string member variable
}

// 1 cm -> 37.7952755906 pixel 
// cmToPixel = (size / cmPerInch) * dpi
std::pair<double, double> DrawCommand::calculateImgDocWidthHeight() {
    auto [width, height] = Application::getDocument()->getFormatSize().second; // std::pair for now, might be {string, pair}
    return {cmToPixel(width), cmToPixel(height)};
}

double DrawCommand::cmToPixel(double length) {
    const auto dpi = 96;
    const auto cmPerInch = 2.54;
    return (length / cmPerInch) * dpi;
}


// auto drawable = std::make_shared<IShape>(type);
// drawable = dynamic_cast(IShape to IVisualDisplayable);
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