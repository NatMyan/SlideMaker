#include "ItemFactory.hpp"

std::shared_ptr<Item> ItemFactory::createItem (Type type, ID id, Position pos, Attributes attributes) {
    if (type == "ellipse") {
        return std::make_shared<Ellipse>(id, pos, attributes);
    }
    else if (type == "line") {
        return std::make_shared<Line>(id, pos, attributes);
    }
    else if (type == "rectangle") {
        return std::make_shared<Rectangle>(id, pos, attributes);
    }
    else if (type == "trapezoid") {
        return std::make_shared<Trapezoid>(id, pos, attributes);
    }
    else if (type == "triangle") {
        return std::make_shared<Triangle>(id, pos, attributes);
    }
    else {
        return nullptr;
    }
}