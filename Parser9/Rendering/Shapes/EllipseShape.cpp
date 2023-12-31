#include "EllipseShape.hpp"

#include <QFont>

namespace ren {

void EllipseShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
    if (!painter) {
        return;
    }

    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;
 
    auto lcolour = defs::toStr(item->getAttribute("-lcolour"));
    auto fcolour = defs::toStr(item->getAttribute("-fcolour"));
    auto lwidth = defs::toDouble(item->getAttribute("-lwidth"));

    qreal centerX = (l + r) / 2.0;
    qreal centerY = (t + b) / 2.0;

    auto angle = defs::toDouble(item->getAttribute("-angle"));

    painter->translate(centerX, centerY);
    painter->rotate(angle);
    painter->translate(-centerX, -centerY);

    QColor lColor {QString::fromUtf8(lcolour)};
    QColor fColor {QString::fromUtf8(fcolour)};

    QPen pen(lColor, lwidth);
    QBrush brush(fColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawEllipse(QRectF(l, t, r - l, b - t));

    VisualShapeBase::draw(painter, item);
}

/*void EllipseShape::setType(std::string type) {
    type_ = type;
}

void EllipseShape::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void EllipseShape::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}

std::shared_ptr<IShape> EllipseShape::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<EllipseShape>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}*/

    // return std::make_unique<EllipseShape>(*this); // deep copy
}

