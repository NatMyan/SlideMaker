#include "ShapeBase.hpp"
#include "../definitions.hpp"

std::unique_ptr<IShape> ShapeBase::clone() {
    return std::make_unique<ShapeBase>(*this); // deep copy
}

void display(std::shared_ptr<ItemBase> item, std::ostream& output) {
    output << "id: " << item->getID() << " type: " << item->getType();
    output << " coords: (" << item->getBoundingBox().first.first << ", " << item->getBoundingBox().first.second << "), ";
    output << "(" << item->getBoundingBox().second.first << ", " << item->getBoundingBox().second.second << ")";
    auto attrs = item->getAttributes();
    for (auto& pair : attrs) {
        output << " " << pair.first << " " << defs::toStr(pair.second);
    }
}

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
