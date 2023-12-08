#include "GroupShape.hpp"

std::unique_ptr<IShape> GroupShape::clone() {
    return std::make_unique<GroupShape>(*this); // deep copy
}

///TODO: rechange this
void GroupShape::draw(QPainter* painter, std::shared_ptr<ItemBase> item) {
    if (!painter) {
        return;
    }
    auto pos = item->getPosition();
    double l = pos.first.first;
    double t = pos.first.second;
    double r = pos.second.first;
    double b = pos.second.second;
 
    auto lcolour = item->getAttribute("-lcolour");
    auto fcolour = item->getAttribute("-fcolour");
    auto lwidth = item->getAttribute("-lwidth");

    Qt::GlobalColor lglobalColor = stringToGlobalColor(lcolour.toString());
    Qt::GlobalColor fglobalColor = stringToGlobalColor(fcolour.toString());
    QPen pen(lglobalColor);
    QBrush brush(fglobalColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    ///TODO: fix this part
    painter->drawShape(QRectF(l, t, r - l, b - t)); 
}