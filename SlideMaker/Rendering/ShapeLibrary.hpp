#ifndef SHAPE_LIBRARY_HPP
#define SHAPE_LIBRARY_HPP

#include "IShape.hpp"
#include "EllipseShape.hpp"
#include "LineShape.hpp"
#include "RectangleShape.hpp"
#include "TriangleShape.hpp"
#include "TrapezoidShape.hpp"
#include "PolygonShape.hpp"
// #include "GroupShape.hpp"

class ShapeLibrary {
    public:
        ShapeLibrary();
        std::shared_ptr<IShape> getShape(std::shared_ptr<Item> item);
    
    private:
        std::unordered_map<std::string, std::shared_ptr<IShape> > items_;
};

#endif // SHAPE_LIBRARY_HPP
