#ifndef RENDERERR_HPP
#define RENDERERR_HPP

#include "../Data/ItemBase.hpp"
#include "../Data/Slide.hpp"

#include <memory>
#include <QImage>

class Renderer {
    public:
        void draw(std::shared_ptr<Slide> slide, const QImage& img);
        void display(std::shared_ptr<ItemBase> item);
        // void display(std::shared_ptr<Item> slide);
};

#endif // RENDERERR_HPP