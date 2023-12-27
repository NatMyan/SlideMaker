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

    auto tcolour = defs::toStr(item->getAttribute("-tcolour"));
    auto text = defs::toStr(item->getAttribute("-text"));
    auto tsize = defs::toDouble(item->getAttribute("-tsize"));
    
    QColor tcolor {QString::fromUtf8(tcolour)};

    painter->setPen(tcolor);

    QFont font("Arial", tsize);
    painter->setFont(font);
    painter->drawText(centerX, centerY, QString::fromUtf8(text));
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
}

}

/*std::unique_ptr<IShape> PolygonShape::clone() {
    return std::make_unique<PolygonShape>(*this); // deep copy
}*/

