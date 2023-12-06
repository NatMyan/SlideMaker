#include "ShapeBase.hpp"

std::unique_ptr<IShape> ShapeBase::clone() {
    return std::make_unique<ShapeBase>(*this); // deep copy
}

void ShapeBase::display(std::shared_ptr<ItemBase> item, std::ostream& output) {
    output << item stuff;
}
