#include "ShapeRegistry.hpp"
#include "WrongShapeException.hpp"

ShapeRegistry::ShapeRegistry () :
    shapeSpec_ {
        "ellipse", "rectangle", "polygon", 
        "trapezoid", "triangle", "line"
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
