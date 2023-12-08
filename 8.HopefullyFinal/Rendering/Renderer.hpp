#ifndef RENDERERR_HPP
#define RENDERERR_HPP

#include "../Data/ItemBase.hpp"
#include "../Data/Slide.hpp"

#include <memory>
#include <QImage>

class Renderer {
    public:
        void draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice);
        void display(std::shared_ptr<ItemBase> item, std::ostream& ostr);
        // void display(std::shared_ptr<Item> slide);
    
    private:
        std::shared_ptr<ShapeLibrary> shapeLib_;
};

#endif // RENDERERR_HPP