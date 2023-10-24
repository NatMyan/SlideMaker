#include "ShapeFactory.hpp"

std::unique_ptr<Shape> ShapeFactory::createShape (Type type, ID id, Position pos, std::map<Key, Value> attributes) {
    if (type == "ellipse") {
        return std::make_unique<Ellipse>(id, pos, attributes);
    }
    else if (type == "line") {
        return std::make_unique<Line>(id, pos, attributes);
    }
    else if (type == "rectangle") {
        return std::make_unique<Rectangle>(id, pos, attributes);
    }
    else if (type == "trapezoid") {
        return std::make_unique<Trapezoid>(id, pos, attributes);
    }
    else if (type == "triangle") {
        return std::make_unique<Triangle>(id, pos, attributes);
    }
    else {
        return nullptr;
    }
}