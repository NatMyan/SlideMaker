#include "ShapeBase.hpp"
#include "../definitions.hpp"

#include <iostream>

std::shared_ptr<IShape> ShapeBase::clone(std::shared_ptr<Item> item) const {
    auto shape = std::make_shared<ShapeBase>();
    // std::cout << "shape made" << std::endl;
    shape->setBBox(item->getBoundingBox());
    // std::cout << "set bbox" << std::endl;
    shape->setType(item->getType());
    // std::cout << "set type" << std::endl;
    shape->setAttrs(item->getAttributes());
    // std::cout << "set attrs" << std::endl;
    return shape; 
}

void ShapeBase::display(std::ostream& output, std::shared_ptr<Item> item) {
    output << "id: " << item->getID() << " type: " << item->getType();
    // std::cout << "id and type" << std::endl;
    
    auto [l, t] = item->getBoundingBox().first;
    auto [r, b] = item->getBoundingBox().second;
    // std::cout << "bbox" << std::endl;
    output << " coords: (" << l << ", " << t << "), " << "(" << r << ", " << b << ")";

    auto attrs = item->getAttributes();
    // std::cout << "get attrs" << std::endl;
    if (attrs != Attributes()) {
        // std::cout << "in attrs if" << std::endl;
        for (auto& pair : attrs) {
            output << " " << pair.first << " " << defs::toStr(pair.second);
        }
    }
    // std::cout << "finish attrs" << std::endl;
}

void ShapeBase::setType(std::string type) {
    type_ = type;
}

void ShapeBase::setBBox(BoundingBox bbox) {
    bbox_ = bbox;
}

void ShapeBase::setAttrs(Attributes attrs) {
    attrs_ = attrs;
}


/*ShapeBase::ShapeBase(std::shared_ptr<ItemInterface> item) :
    id_(item->getID()),
    type_(item->getType()),
    bbox_(item->getBoundingBox()),
    attrs_(item->getAttributes())
{}*/

/*void ShapeBase::display(VariantWrapper<std::shared_ptr<Item>, std::shared_ptr<ItemGroup> > item, std::ostream& output) {
    if (item.holdsAlternative<std::shared_ptr<Item> >()) 
        display2(item.get<std::shared_ptr<Item> >(), output);
    else if (item.holdsAlternative<std::shared_ptr<ItemGroup> >()) 
        display2(item.get<std::shared_ptr<ItemGroup> >(), output);
}

template <typename T>
void ShapeBase::display2(T item, std::ostream& output) {
    output << "id: " << item->getID() << " type: " << item->getType();
    output << " coords: (" << item->getBoundingBox().first.first << ", " << item->getBoundingBox().first.second << "), ";
    output << "(" << item->getBoundingBox().second.first << ", " << item->getBoundingBox().second.second << ")";
    auto attrs = item->getAttributes();
    for (auto& pair : attrs) {
        output << " " << pair.first << " " << pair.second;
    }
}
*/
