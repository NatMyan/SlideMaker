#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "Item.hpp"
#include "Ellipse.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include "Triangle.hpp"

#include <memory>

class ItemFactory {
    public:
        static std::shared_ptr<Item> createItem (Type type, ID id, Position pos, Attributes attributes);

};

#endif // SHAPE_FACTRY_HPP