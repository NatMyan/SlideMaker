#include "RectangleShape.hpp"

std::unique_ptr<IShape> RectangleShape::clone() {
    return std::make_unique<RectangleShape>(*this); // deep copy
}

void RectangleShape::draw(QPainter* painter, std::shared_ptr<ItemBase> item) {
    
}

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
