#include "PolygonShape.hpp"

namespace ren {

///TODO: rechange this
void PolygonShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
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

    auto sideCount = defs::toDouble(item->getAttribute("-sideCount"));
    auto vertices = takeVertices(l, t, r, b, sideCount);

    QColor lColor {QString::fromUtf8(lcolour)};
    QColor fColor {QString::fromUtf8(fcolour)};

    QPen pen(lColor, lwidth);
    QBrush brush(fColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    
    painter->drawPolygon(vertices.data(), sideCount);
}

QVector<QPointF> PolygonShape::takeVertices(double l, double t, double r, double b, double sideCount) {
    auto boundingRect = QRectF(l, t, r - l, b - t);
    QPointF center = boundingRect.center();
    qreal radius = qMin(boundingRect.width(), boundingRect.height()) / 2.0;
    qreal angleIncrement = 360.0 / sideCount;

    QVector<QPointF> vertices;
    for (int i = 0; i < sideCount; ++i) {
        qreal angle = i * angleIncrement;
        qreal x = center.x() + radius * qCos(qDegreesToRadians(angle));
        qreal y = center.y() + radius * qSin(qDegreesToRadians(angle));
        vertices.append(QPointF(x, y));
    }
    return vertices;
}

void PolygonShape::setType(std::string type) {
    type_ = type;
}

void PolygonShape::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void PolygonShape::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}

std::shared_ptr<IShape> PolygonShape::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<PolygonShape>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}

}

/*std::unique_ptr<IShape> PolygonShape::clone() {
    return std::make_unique<PolygonShape>(*this); // deep copy
}*/

