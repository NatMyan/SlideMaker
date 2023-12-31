#ifndef VISUAL_SHAPE_BASE_HPP
#define VISUAL_SHAPE_BASE_HPP

#include "ShapeBase.hpp"
#include "../IShape.hpp"
#include "../ITextDisplayable.hpp"
#include "../IVisualDisplayable.hpp"
#include "../../Data/Item.hpp"
#include "../../Data/IItemVisitor.hpp"

#include <ostream>
#include <memory>

namespace ren {

///NOTE: decorator pattern

using Attributes = dat::Attributes;

class VisualShapeBase : public ShapeBase, public IVisualDisplayable {
    public:
        void draw(QPainter* painter, std::shared_ptr<Item> item) override; // decorator pattern
        std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override final;

    public:
        void setType(std::string type);
        void setBBox(BoundingBox bbox);
        void setAttrs(Attributes attrs);
        
    private:
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;
};

}
#endif // VISUAL_SHAPE_BASE_HPP