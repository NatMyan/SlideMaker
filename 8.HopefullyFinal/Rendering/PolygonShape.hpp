#ifndef POLYGON_SHAPE_HPP
#define POLYGON_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class PolygonShape : public ShapeBase, public IVisualDisplayable {
    public:
        std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<ItemBase> item);
};

#endif // POLYGON_SHAPE_HPP