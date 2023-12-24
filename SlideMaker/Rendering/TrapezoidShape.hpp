#ifndef TRAPEZOID_SHAPE_HPP
#define TRAPEZOID_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class TrapezoidShape : public ShapeBase, public IVisualDisplayable {
    public:
        // std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif // TRAPEZOID_SHAPE_HPP