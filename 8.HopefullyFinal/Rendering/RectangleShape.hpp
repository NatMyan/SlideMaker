#ifndef RECTANGLE_SHAPE_HPP
#define RECTANGLE_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class RectangleShape : public ShapeBase, public IVisualDisplayable {
    public:
        // std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif // RECTANGLE_SHAPE_HPP