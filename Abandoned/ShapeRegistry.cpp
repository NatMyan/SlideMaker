#include "ShapeRegistry.hpp"
#include "Shapes/WrongShapeException.hpp"

ShapeRegistry::ShapeRegistry () :
    shapeSpec_ {
        "Ellipse", "Rectangle", "Polygon", 
        "Trapezoid", "Triangle", "Line"
    }
{}

/// NOTE: same as commandRegistry, but w/different name
ShapeNameType ShapeRegistry::findShape (const std::string& shapeName) {
    for (const auto& shp : shapeSpec_) {
        if (shapeName == shp) {
            return shp;
        }
    }
    throw WrongShapeException(shapeName);
}
