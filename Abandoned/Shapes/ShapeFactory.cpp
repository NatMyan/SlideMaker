#include "ShapeFactory.hpp"

std::shared_ptr<Shape> ShapeFactory::createShape (Type type, ID id, Position pos, std::map<Key, Value> attributes) {
    if (type == "ellipse") {
        return std::make_shared<Ellipse>(type, id, pos, attributes);
    }
    else if (type == "line") {
        return std::make_shared<Line>(type, id, pos, attributes);
    }
    else if (type == "rectangle") {
        return std::make_shared<Rectangle>(type, id, pos, attributes);
    }
    else if (type == "trapezoid") {
        return std::make_shared<Trapezoid>(type, id, pos, attributes);
    }
    else if (type == "triangle") {
        return std::make_shared<Triangle>(type, id, pos, attributes);
    }
    else {
        return nullptr;
    }
}