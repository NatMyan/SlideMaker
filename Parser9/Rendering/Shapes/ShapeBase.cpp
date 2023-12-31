#include "ShapeBase.hpp"
#include "../../zhelpers/Definitions.hpp"

#include <iostream>

namespace ren {

void ShapeBase::display(std::ostream& output, std::shared_ptr<Item> item) {
    output << "id: " << item->getID() << " type: " << item->getType();
    
    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;
    output << " coords: (" << l << ", " << t << "), " << "(" << r << ", " << b << ")";

    auto attrs = item->getAttributes();
    if (attrs != Attributes()) {
        for (auto& pair : attrs) {
            output << " " << pair.first << " " << defs::toStr(pair.second);
        }
    }
}

/*void ShapeBase::draw(QPainter* painter, std::shared_ptr<Item> item) {
    if (!painter) {
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
    painter->drawText(centerX, centerY, QString::fromUtf8(text));
}*/


/*std::shared_ptr<IShape> ShapeBase::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<ShapeBase>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}

void ShapeBase::setType(std::string type) {
    type_ = type;
}

void ShapeBase::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void ShapeBase::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}*/

}