#ifndef POLYGON_SHAPE_HPP
#define POLYGON_SHAPE_HPP

#include "ShapeBase.hpp"
#include "../IVisualDisplayable.hpp"

namespace ren {

class PolygonShape : public ShapeBase { //,  public IVisualDisplayable {
    public:
        std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override;
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
    
    private:
        QVector<QPointF> takeVertices(double l, double t, double r, double b, double sideCount);

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

#endif // POLYGON_SHAPE_HPP