/*#include "ItemBase.hpp"
#include "../Exception.hpp"

ItemBase::ItemBase (int id, BoundingBox bbox, Attributes attributes) :
    id_(id),
    bbox_(bbox),
    attrs_(attributes)
{}

int ItemBase::getID() const {
    return id_;
}

BoundingBox ItemBase::getBoundingBox() const {
    return bbox_;
}

void ItemBase::setBoundingBox(BoundingBox bbox) {
    bbox_ = bbox;
}

Value ItemBase::getAttribute(Key key) const {
    if (attrs_.getValue(key) != Value())  
        return attrs_.getValue(key);
    throw Exception("Attribute not found");
}

void ItemBase::setAttribute(Key key, Value value) {
    attrs_.setPair(key, value);
}

Attributes ItemBase::getAttributes() const {
    return attrs_;
}

void ItemBase::setAttributes(Attributes attrs) {
    for (const auto& pair : attrs) {
        const auto& key = pair.first;
        const auto& val = pair.second;
        attrs_.setPair(key, val);
    }
}*/