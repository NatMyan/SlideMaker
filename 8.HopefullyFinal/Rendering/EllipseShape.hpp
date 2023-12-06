#ifndef ELLIPSE_SHAPE_HPP
#define ELLIPSE_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class EllipseShape : public ShapeBase, public IVisualDisplayable {
    public:
        std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<ItemBase> item);
};

#endif // ELLIPSE_SHAPE_HPP