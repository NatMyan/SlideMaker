#include "ShapeLibrary.hpp"

#include <string>
#include <iostream>

namespace ren {

ShapeLibrary::ShapeLibrary () {
    items_["rectangle"] = std::make_shared<RectangleShape>();
    items_["triangle"] = std::make_shared<TriangleShape>();
    items_["trapezoid"] = std::make_shared<TrapezoidShape>();
    items_["ellipse"] = std::make_shared<EllipseShape>();
    items_["line"] = std::make_shared<LineShape>();
    items_["polygon"] = std::make_shared<PolygonShape>();
    items_["text"] = std::make_shared<TextShape>();
}

std::shared_ptr<VisualShapeBase> ShapeLibrary::getShape(std::shared_ptr<Item> item) {
    auto it = items_.find(item->getType());
    // std::cout << item->getType() << " type" << std::endl;
    if (it != items_.end()) {
        // std::cout << "clone " << std::endl;
        return std::dynamic_pointer_cast<VisualShapeBase>(it->second->clone(item));
    }
    // std::cout << "null " << std::endl;
    return nullptr; 
}

}

