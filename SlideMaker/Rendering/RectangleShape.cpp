#include "RectangleShape.hpp"

#include <iostream>

///TODO: rechange this
void RectangleShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
    if (!painter) {
        // std::cout << "!pianter" << std::endl;
        return;
    }

    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;
    // std::cout << "bbox" << l << " " << t << " " << r << " " << b << std::endl;
 
    auto lcolour = defs::toStr(item->getAttribute("-lcolour"));
    // std::cout << "lcolour" << lcolour << std::endl;
    auto fcolour = defs::toStr(item->getAttribute("-fcolour"));
    // std::cout << "fcolor" << fcolour << std::endl;
    auto lwidth = defs::toDouble(item->getAttribute("-lwidth"));
    // std::cout << "lwidth" << lwidth << std::endl;

    qreal centerX = (l + r) / 2.0;
    qreal centerY = (t + b) / 2.0;
    // std::cout << "centers" << centerX << " " << centerY << std::endl;

    auto angle = defs::toDouble(item->getAttribute("-angle"));
    // std::cout << "angle" << angle << std::endl;

    painter->translate(centerX, centerY);
    // std::cout << "translate" << std::endl;
    painter->rotate(angle);
    // std::cout << "rotate" << std::endl;
    painter->translate(-centerX, -centerY);
    // std::cout << "translate2" << std::endl;

    QColor lColor {QString::fromUtf8(lcolour)};
    QColor fColor {QString::fromUtf8(fcolour)};
    // std::cout << "f l colours" << std::endl;

    QPen pen(lColor, lwidth);
    // std::cout << "create pen" << std::endl;
    QBrush brush(fColor);
    // std::cout << "brush create" << std::endl;
    
    painter->setPen(pen);
    // std::cout << "set pen" << std::endl;
    painter->setBrush(brush);
    // std::cout << "brush set" << std::endl;

    painter->drawRect(QRectF(l, t, r - l, b - t));
    // std::cout << "drawRect" << std::endl;

    auto tcolour = defs::toStr(item->getAttribute("-tcolour"));
    auto text = defs::toStr(item->getAttribute("-text"));
    auto tsize = defs::toDouble(item->getAttribute("-tsize"));
    
    QColor tcolor {QString::fromUtf8(tcolour)};

    painter->setPen(tcolor);

    QFont font("Arial", tsize);
    painter->setFont(font);
    painter->drawText(centerX, centerY, QString::fromUtf8(text));
}

/*std::unique_ptr<IShape> RectangleShape::clone() {
    return std::make_unique<RectangleShape>(*this); // deep copy
}*/

/*
    if (!painter) {
        return;
    }
    auto pos = itemPtr_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
 
    auto lcolour = itemPtr_->getAttribute("-lcolour");
    auto fcolour = itemPtr_->getAttribute("-fcolour");
    auto lwidth = itemPtr_->getAttribute("-lwidth");

    Qt::GlobalColor lglobalColor = stringToGlobalColor(lcolour.toString());
    Qt::GlobalColor fglobalColor = stringToGlobalColor(fcolour.toString());
    QPen pen(lglobalColor);
    QBrush brush(fglobalColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(QRectF(l, t, r - l, b - t));
    // painter->fillRect(QRectF(l, t, r - l, b - t), fglobalColor);
*/
