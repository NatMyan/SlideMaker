#include "RectangleRenderer.hpp"
#include "../VariantWrapper.hpp"

#include <QColor>
#include <QPen>
#include <QBrush>
#include <QString>
#include <QHash>

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
 
    auto lcolour = itemPtr_->getAttribute("-lcolour");
    auto fcolour = itemPtr_->getAttribute("-fcolour");
    auto lwidth = itemPtr_->getAttribute("-lwidth");

    Qt::GlobalColor lglobalColor = stringToGlobalColor(lcolour.toString());
    QPen pen(lglobalColor);
    QBrush brush(lglobalColor);
    
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(QRectF(l, t, r - l, b - t));
    
    Qt::GlobalColor fglobalColor = stringToGlobalColor(fcolour.toString());
    painter->fillRect(QRectF(l, t, r - l, b - t), fglobalColor);
}


