#include "TrapezoidShape.hpp"

namespace ren {

///TODO: rechange this
void TrapezoidShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
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

    auto upLeft = (3 * l + r) / 4.0;  // (l + ((r+l) / 2.0)) / 2.0;
    auto upRight = (3 * r + l) / 4.0;
    QList<QPointF> pairs = {{upLeft, t}, {l, b}, {r, b}, {upRight, t}};
    painter->drawPolygon(pairs);

    auto tcolour = defs::toStr(item->getAttribute("-tcolour"));
    auto text = defs::toStr(item->getAttribute("-text"));
    auto tsize = defs::toDouble(item->getAttribute("-tsize"));
    
    QColor tcolor {QString::fromUtf8(tcolour)};

    painter->setPen(tcolor);

    QFont font("Arial", tsize);
    painter->setFont(font);
    painter->drawText(centerX, centerY, QString::fromUtf8(text));
}

}

/*std::unique_ptr<IShape> TrapezoidShape::clone() {
    return std::make_unique<TrapezoidShape>(*this); // deep copy
}*/