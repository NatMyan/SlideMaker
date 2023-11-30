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

// QColor(int r, int g, int b, int a = 255)
///TODO: bad design, change it someday
Qt::GlobalColor RectangleRenderer::stringToGlobalColor(const QString& colorName) {
    static const QHash<QString, Qt::GlobalColor> colorMap = {
        {"red", Qt::red},
        {"green", Qt::green},
        {"blue", Qt::blue},
        {"yellow", Qt::yellow},
        {"darkYellow", Qt::darkYellow},
    };

    return colorMap.value(colorName, Qt::black); // Default to black if the color is not found
}

/*void setPenAndBrushFromColorString(const QString& colorName) {
    Qt::GlobalColor globalColor = stringToGlobalColor(colorName);

    QPen pen(globalColor);
    
    QBrush brush(globalColor);

}*/