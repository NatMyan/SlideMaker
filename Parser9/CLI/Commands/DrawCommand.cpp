#include "DrawCommand.hpp"
#include "../../Application.hpp"
#include "../../Rendering/Renderer.hpp"
#include "../../Rendering/DimensionConverter.hpp"

#include <QPainter>
#include <QFile>
#include <iostream>

namespace cli {

using Renderer = ren::Renderer;

DrawCommand::DrawCommand(const Map& info) :
    infoMap_(info)
{}

void DrawCommand::execute() {
    auto app = app::Application::getApplication();
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>(); 
    
    ID idx = takeIndex();

    auto slide = app->getDocument()->getSlide(idx);
    if (slide) {
        QString filePath;
        try { filePath = QString::fromUtf8(defs::toStr(infoMap_["-file"])); }
        catch (const std::out_of_range& e) { throw InvalidFileException("File not found"); }

        QFile file(filePath);
        auto [convWidth, convHeight] = takeConvertedSize();

        if (file.exists()) { throw FileExistsException("File exists: " + filePath.toStdString()); }
        else {
            if (file.open(QIODevice::WriteOnly)) {
                QImage img(convWidth, convHeight, QImage::Format_ARGB32);
                renderer->draw(slide, &img);

                if (!img.save(filePath)) { throw FailedToSaveException("Image failed to get saved: " + filePath.toStdString()); }
                file.close();
            } 
            else { throw FileDidNotOpenException("File didn't open: " + filePath.toStdString()); }
        }
    }
    else { throw InvalidSlideException("Slide is nullptr"); }
}

ID DrawCommand::takeIndex() {
    ID idx;
    try { idx = defs::toInt(infoMap_["-idx"]); }
    catch (const std::exception& e) { idx = app::Application::getApplication()->getDirector()->getActiveSlideIdx(); }
    return idx;
}

std::pair<double, double> DrawCommand::takeConvertedSize() {
    auto [width, height] = app::Application::getApplication()->getDocument()->getFormatSize().second;
    std::unique_ptr<ren::DimensionConverter> converter = std::make_unique<ren::DimensionConverter>();
    auto [convWidth, convHeight] = converter->calculateImgDocWidthHeight(width, height);
    return {convWidth, convHeight};
}

}
