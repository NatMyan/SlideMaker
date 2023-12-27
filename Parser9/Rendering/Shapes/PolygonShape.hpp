#ifndef POLYGON_SHAPE_HPP
#define POLYGON_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

namespace ren {

class PolygonShape : public ShapeBase, public IVisualDisplayable {
    public:
        // std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
    
    private:
        QVector<QPointF> takeVertices(double l, double t, double r, double b, double sideCount);
};

}

#endif // POLYGON_SHAPE_HPP