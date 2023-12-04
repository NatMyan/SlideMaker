#include "LineRenderer.hpp"

LineRenderer::LineRenderer(Idx idx, std::shared_ptr<Item> itemPtr) :
    IShapeRenderer(idx, itemPtr),
    idx_(idx),
    itemPtr_(itemPtr)
{}

void LineRenderer::draw(QPainter* painter) {
    if (!painter) {
        return;
    }
    auto pos = itemPtr_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
    
    auto lcolour = itemPtr_->getAttribute("-lcolour");
    auto lwidth = itemPtr_->getAttribute("-lwidth");

    Qt::GlobalColor lglobalColor = stringToGlobalColor(lcolour.toString());
    QPen pen(lglobalColor);
    QBrush brush(lglobalColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawLine(QPointF(l,t) ,QPointF(r,b));
}