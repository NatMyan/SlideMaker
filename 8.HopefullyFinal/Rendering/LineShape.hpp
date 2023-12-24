#ifndef LINE_SHAPE_HPP
#define LINE_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class LineShape : public ShapeBase, public IVisualDisplayable {
    public:
        // std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif // LINE_SHAPE_HPP