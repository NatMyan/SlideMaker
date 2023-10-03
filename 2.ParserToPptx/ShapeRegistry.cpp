#include "ShapeRegistry.hpp"

ShapeRegistry::ShapeRegistry () :
    shapeSpec {
        "Ellipse", "Rectangle", "Polygon", 
        "Trapezoid", "Triangle", "Line"
    }
{}

/// NOTE: same as commandRegistry, but w/different name
ShapeNameType ShapeRegistry::findShape (const std::string& shapeName) {
    std::string wrongShapeErrorMsg = "wrong_shape";
    for (const auto& shp : shapeSpec) 
        if (shapeName == shp) 
            return shp;
    return wrongShapeErrorMsg;
}
