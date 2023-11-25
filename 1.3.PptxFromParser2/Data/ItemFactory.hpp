#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "Items/Item.hpp"
#include "Items/Ellipse.hpp"
#include "Items/Line.hpp"
#include "Items/Rectangle.hpp"
#include "Items/Trapezoid.hpp"
#include "Items/Triangle.hpp"

#include <memory>

class ItemFactory {
    public:
        static std::shared_ptr<Item> createItem (Type type, ID id, Position pos, Attributes attributes);

};

#endif // SHAPE_FACTRY_HPP