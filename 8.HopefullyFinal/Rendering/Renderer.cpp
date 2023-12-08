#include "Renderer.hpp"

void Renderer::display(std::shared_ptr<ItemBase> item, std::ostream& ostr) {
    std::shared_ptr<IShape> shape = shapeLib_->getShape(item->getType());
    auto ptr = std::dynamic_pointer_cast<ITextDisplayable>(shape);
    ptr->display(item, ostr);
}

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice) {
    QPainter* painter = new QPainter;
    painter->begin(paintDevice);
    std::shared_ptr<IShape> shape = shapeLib_->getShape(item->getType());
    auto ptr = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
    ptr->draw(painter, shape);
    painter->end();
}