#include "RectangleRenderer.hpp"

RectangleRenderer::RectangleRenderer(Idx idx, std::shared_ptr<Item> itemPtr) : 
    IShapeRenderer(idx, itemPtr),
    idx_(idx),
    itemPtr_(itemPtr)
{}

void RectangleRenderer::draw(QPainter* painter) {
    if (!painter) {
        return;
    }
    auto pos = itemPtr_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
 
    painter->drawRect(QRectF(l, t, r - l, b - t));
    auto colour = itemPtr_->getAttribute("-fcolour");
    painter->fillRect(QRectF(l, t, r - l, b - t), "r");
}