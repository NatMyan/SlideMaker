#include "ShapeBase.hpp"
#include "../../zhelpers/Definitions.hpp"

#include <iostream>

namespace ren {

/*std::shared_ptr<IShape> ShapeBase::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<ShapeBase>();
    shape->setBBox(item->getBoundingBox());
    shape->setType(item->getType());
    shape->setAttrs(item->getAttributes());
    return shape; 
}*/

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

/*void ShapeBase::setType(std::string type) {
    type_ = type;
}

void ShapeBase::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void ShapeBase::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}*/

}