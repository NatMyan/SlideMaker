#ifndef GROUP_SHAPE_HPP
#define GROUP_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class GroupShape : public ShapeBase, public IVisualDisplayable {
    public:
        std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<ItemBase> item);
};

#endif // GROUP_SHAPE_HPP