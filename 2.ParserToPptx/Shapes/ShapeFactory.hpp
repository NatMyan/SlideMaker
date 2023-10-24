#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "Shape.hpp"
#include "Ellipse.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include "Triangle.hpp"

#include <memory>

class ShapeFactory {
    public:
        std::unique_ptr<Shape> createShape (Type type, ID id, Position pos, std::map<Key, Value> attributes);

};

#endif // SHAPE_FACTRY_HPP