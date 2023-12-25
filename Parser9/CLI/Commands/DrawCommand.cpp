#include "DrawCommand.hpp"
#include "../../Application.hpp"
#include "../../Rendering/Renderer.hpp"
#include "../../Rendering/DimensionConverter.hpp"

#include <QPainter>
#include <QFile>
#include <iostream>

DrawCommand::DrawCommand(const Map& info) :
    infoMap_(info)
{}

void DrawCommand::execute() {
    auto app = Application::getApplication();
    std::shared_ptr<Renderer> renderer = app->getRenderer(); // this or the one above ?
    auto idx = defs::toInt(infoMap_["-idx"]);
    auto slide = app->getDocument()->getSlide(idx);
    if (slide) {
        auto filePath = QString::fromUtf8(defs::toStr(infoMap_["-file"]));
        std::cout << filePath.toStdString()  << " file" << std::endl;
        QFile file(filePath);
        auto [width, height] = app->getDocument()->getFormatSize().second;
        std::unique_ptr<DimensionConverter> converter = std::make_unique<DimensionConverter>();
        auto [convWidth, convHeight] = converter->calculateImgDocWidthHeight(width, height);

        if (file.exists()) {
            QImage img(convWidth, convHeight, QImage::Format_ARGB32);
            renderer->draw(slide, &img);
            if (img.save(filePath)) {
                std::cout << "Image saved successfully." << std::endl;
            } 
            else {
                std::cerr << "Error: Failed to save the image." << std::endl;
            }
        }
        else {
            if (file.open(QIODevice::WriteOnly)) {
                std::cout << "File created successfully." << std::endl;
                // file.close();
                // std::cout << "File closed." << std::endl;
                QImage img(convWidth, convHeight, QImage::Format_ARGB32);
                std::cout << "Img created." << std::endl;
                renderer->draw(slide, &img);
                std::cout << "renderer called." << std::endl;

                if (img.save(filePath)) {
                    std::cout << "Image saved successfully." << std::endl;
                    file.close();
                    std::cout << "File closed." << std::endl;
                } 
                else {
                    std::cerr << "Error: Failed to save the image." << std::endl;
                }
                file.close();
                std::cout << "File closed2." << std::endl;
            } 
            else {
                std::cerr << "Error: Failed to create the file." << std::endl;
            }
        }
    }
}

/*
#include <QFile>

// ...

auto filePath = QString::fromUtf8(defs::toStr(infoMap_["-file"]));
std::cout << filePath.toStdString() << " file" << std::endl;

QFile file(filePath);

if (file.exists()) {
    // File exists, proceed with saving the image.
    QImage img(convWidth, convHeight, QImage::Format_ARGB32);
    renderer->draw(slide, &img);

    if (img.save(filePath)) {
        std::cout << "Image saved successfully." << std::endl;
    } else {
        std::cerr << "Error: Failed to save the image." << std::endl;
    }
} 
else {
    // File doesn't exist, attempt to create it.
    if (file.open(QIODevice::WriteOnly)) {
        std::cout << "File created successfully." << std::endl;
        file.close();

        // Proceed with saving the image.
        QImage img(convWidth, convHeight, QImage::Format_ARGB32);
        renderer->draw(slide, &img);

        if (img.save(filePath)) {
            std::cout << "Image saved successfully." << std::endl;
        } 
        else {
            std::cerr << "Error: Failed to save the image." << std::endl;
        }
    } 
    else {
        std::cerr << "Error: Failed to create the file." << std::endl;
    }
}
*/