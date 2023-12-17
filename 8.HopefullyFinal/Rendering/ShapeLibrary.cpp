#include "ShapeLibrary.hpp"

#include <string>

std::shared_ptr<IShape> ShapeLibrary::getShape(std::shared_ptr<Item> item) {
///NOTE: PRETEND THIS IF ELSE IS A MAP
    auto type = item->getType();
    if (type == "rectangle") return std::make_shared<RectangleShape>();
    else if (type == "triangle") return std::make_shared<TriangleShape>();
    else if (type == "trapezoid") return std::make_shared<TrapezoidShape>();
    else if (type == "ellipse") return std::make_shared<EllipseShape>();
    else if (type == "line") return std::make_shared<LineShape>();
    else if (type == "polygon") return std::make_shared<PolygonShape>();
    // else if (type == "itemGroup") return std::make_shared<GroupShape>();
}