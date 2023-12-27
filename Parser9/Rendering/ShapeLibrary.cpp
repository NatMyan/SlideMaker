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
}

std::shared_ptr<IShape> ShapeLibrary::getShape(std::shared_ptr<Item> item) {
    auto it = items_.find(item->getType());
    if (it != items_.end()) {
        return it->second->clone(item);
    }
    return nullptr; 
}

}

/*std::shared_ptr<IShape> ShapeLibrary::getShape(std::shared_ptr<Item> item) {
///NOTE: PRETEND THIS IF ELSE IS A MAP
    auto type = item->getType();
    if (type == "rectangle") return std::make_shared<RectangleShape>();
    else if (type == "triangle") return std::make_shared<TriangleShape>();
    else if (type == "trapezoid") return std::make_shared<TrapezoidShape>();
    else if (type == "ellipse") return std::make_shared<EllipseShape>();
    else if (type == "line") return std::make_shared<LineShape>();
    else if (type == "polygon") return std::make_shared<PolygonShape>();
    // else if (type == "itemGroup") return std::make_shared<GroupShape>();
}*/
