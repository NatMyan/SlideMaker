#include "LineShape.hpp"

namespace ren {

void LineShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
    if (!painter) {
        return;
    }

    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;
 
    auto lcolour = defs::toStr(item->getAttribute("-lcolour"));
    auto lwidth = defs::toDouble(item->getAttribute("-lwidth"));

    auto angle = defs::toDouble(item->getAttribute("-angle"));
    qreal centerX = (l + r) / 2.0;
    qreal centerY = (t + b) / 2.0;

    painter->translate(centerX, centerY);
    painter->rotate(angle);
    painter->translate(-centerX, -centerY);

    QColor lColor {QString::fromUtf8(lcolour)};

    QPen pen(lColor, lwidth);

    painter->setPen(pen);

    painter->drawLine(l, t, r, b);

    VisualShapeBase::draw(painter, item);
}

/*void LineShape::setType(std::string type) {
    type_ = type;
}

void LineShape::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void LineShape::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}

std::shared_ptr<IShape> LineShape::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<LineShape>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}*/

}

/*std::unique_ptr<IShape> LineShape::clone() {
    return std::make_unique<LineShape>(*this); // deep copy
}*/