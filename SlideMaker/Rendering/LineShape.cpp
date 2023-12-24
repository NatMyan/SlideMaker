#include "LineShape.hpp"

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

    auto tcolour = defs::toStr(item->getAttribute("-tcolour"));
    auto text = defs::toStr(item->getAttribute("-text"));
    auto tsize = defs::toDouble(item->getAttribute("-tsize"));
    
    QColor tcolor {QString::fromUtf8(tcolour)};

    painter->setPen(tcolor);

    QFont font("Arial", tsize);
    painter->setFont(font);
    painter->drawText(centerX, centerY, QString::fromUtf8(text));
}

/*std::unique_ptr<IShape> LineShape::clone() {
    return std::make_unique<LineShape>(*this); // deep copy
}*/