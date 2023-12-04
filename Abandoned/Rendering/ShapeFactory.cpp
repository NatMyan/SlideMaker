#include "ShapeFactory.hpp"
#include "EllipseRenderer.hpp"
#include "LineRenderer.hpp"
#include "PolygonRenderer.hpp"
#include "RectangleRenderer.hpp"
#include "TrapezoidRenderer.hpp"
#include "TriangleRenderer.hpp"

std::shared_ptr<IShapeRenderer> ShapeFactory::createShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr) {
    Type type = itemPtr->getType();
    if (type == std::string("ellipse")) {
        return std::make_shared<EllipseRenderer>(idx, itemPtr);
    }
    else if (type == std::string("line")) {
        return std::make_shared<LineRenderer>(idx, itemPtr);
    }
    else if (type == std::string("polygon")) {
        return std::make_shared<PolygonRenderer>(idx, itemPtr);
    }
    else if (type == std::string("ractangle")) {
        return std::make_shared<RectangleRenderer>(idx, itemPtr);
    }
    else if (type == std::string("trapezoid")) {
        return std::make_shared<TrapezoidRenderer>(idx, itemPtr);
    }
    else if (type == std::string("triangle")) {
        return std::make_shared<TriangleRenderer>(idx, itemPtr);
    }
}