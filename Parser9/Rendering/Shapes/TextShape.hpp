#ifndef TEXT_SHAPE_HPP
#define TEXT_SHAPE_HPP

#include "VisualShapeBase.hpp"
#include "../IVisualDisplayable.hpp"

namespace ren {

class TextShape : public VisualShapeBase { //,  public IVisualDisplayable {
    public:
        // TextShape(std::shared_ptr<IShape> ogShape);
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
        /*std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override;
    
    public:
        void setType(std::string type);
        void setBBox(BoundingBox bbox);
        void setAttrs(Attributes attrs);
        
    private:
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;*/
};

}

#endif // TEXT_SHAPE_HPP