#include "TextShape.hpp"

namespace ren {

void TextShape::draw(QPainter* painter, std::shared_ptr<Item> item) {
    VisualShapeBase::draw(painter, item);
    /*if (!painter) {
        return;
    }
    
    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;

    qreal centerX = (l + r) / 2.0;
    qreal centerY = (t + b) / 2.0;

    auto angle = defs::toDouble(item->getAttribute("-angle"));

    painter->translate(centerX, centerY);
    painter->rotate(angle);
    painter->translate(-centerX, -centerY);

    auto tcolour = defs::toStr(item->getAttribute("-tcolour"));
    auto text = defs::toStr(item->getAttribute("-text"));
    auto tsize = defs::toDouble(item->getAttribute("-tsize"));
    auto tfont = defs::toStr(item->getAttribute("-tfont"));
    
    QColor tcolor {QString::fromUtf8(tcolour)};

    painter->setPen(tcolor);

    QFont font(QString::fromUtf8(tfont), tsize);
    painter->setFont(font);
    painter->drawText(centerX, centerY, QString::fromUtf8(text));*/
}

/*void TextShape::setType(std::string type) {
    type_ = type;
}

void TextShape::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void TextShape::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}

std::shared_ptr<IShape> TextShape::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<TextShape>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}*/

}