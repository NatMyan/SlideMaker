#ifndef ELLIPSE_SHAPE_HPP
#define ELLIPSE_SHAPE_HPP

#include "ShapeBase.hpp"
#include "../IVisualDisplayable.hpp"

namespace ren {

class EllipseShape : public ShapeBase { //}, public IVisualDisplayable {
    public:
        std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override;
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;

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

#endif // ELLIPSE_SHAPE_HPP