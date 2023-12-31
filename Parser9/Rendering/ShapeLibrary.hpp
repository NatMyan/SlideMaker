#ifndef SHAPE_LIBRARY_HPP
#define SHAPE_LIBRARY_HPP

#include "IShape.hpp"
#include "Shapes/EllipseShape.hpp"
#include "Shapes/LineShape.hpp"
#include "Shapes/RectangleShape.hpp"
#include "Shapes/TriangleShape.hpp"
#include "Shapes/TrapezoidShape.hpp"
#include "Shapes/PolygonShape.hpp"
#include "Shapes/TextShape.hpp"
#include "Shapes/VisualShapeBase.hpp"

namespace ren {

class ShapeLibrary {
    public:
        ShapeLibrary();
        std::shared_ptr<VisualShapeBase> getShape(std::shared_ptr<Item> item);
    
    private:
        std::unordered_map<std::string, std::shared_ptr<VisualShapeBase> > items_;
};

}

#endif // SHAPE_LIBRARY_HPP
