#include "Renderer.hpp"

#include <iostream>

namespace ren {

Renderer::Renderer() :
    shapeLib_(std::make_shared<ShapeLibrary>())
{}

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice) {
    QPainter* painter = new QPainter;

    // painter->save();
    painter->begin(paintDevice);
    for (auto it = slide->getItemGroup()->begin(); it != slide->getItemGroup()->end(); ++it) {
        auto item = (*it);
        std::shared_ptr<IShape> shape = shapeLib_->getShape(item);
        if (shape) {
            std::cout << "shape isn't nullptr" << std::endl;
            std::shared_ptr<IVisualDisplayable> ptr = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
            if (ptr) {
                std::cout << "ptr isn't nullptr, yey" << std::endl;
                ptr->draw(painter, item);
            }
            else { throw InvalidPointerException("Ptr is nullptr"); }
        }
        else { throw InvalidShapeException("Shape is nullptr"); }
    }
    // painter->restore();
    painter->end();
}

void Renderer::display(std::shared_ptr<Item> item, std::ostream& ostr) {
    takeOstream(ostr);
    visitItem(*item);
    // item->accept(*this);
}

void Renderer::display(std::shared_ptr<Slide> slide, std::ostream& ostr) {
    takeOstream(ostr);
    visitItemGroup(*(slide->getItemGroup()));
    // slide->getItemGroup()->accept(*this);
}

void Renderer::visitItem(const Item& item) {
    auto itemPtr = std::make_shared<Item>(item);
    std::shared_ptr<IShape> shape = shapeLib_->getShape(itemPtr);
    auto ptr = std::dynamic_pointer_cast<ITextDisplayable>(shape);
    if (ostr_) {
        if (ptr) {
            ptr->display(*ostr_, itemPtr);
        }
        else {
            // std::cout << "no ptr" << std::endl;
        }
    }
    else {
        // std::cout << "ostr doesn't work" << std::endl;
    }
}

void Renderer::visitItemGroup(const ItemGroup& itemGroup) {
    auto itemgroupPtr = std::make_shared<ItemGroup>(itemGroup);
    for (auto it = itemgroupPtr->begin(); it != itemgroupPtr->end(); ++it) {
        auto item = *it;
        visitItem(*item);
    }
}

void Renderer::takeOstream(std::ostream& ostr) {
    ostr_ = &ostr;
}

}

