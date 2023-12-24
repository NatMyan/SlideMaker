#include "Item.hpp"
#include "../Exception.hpp"

///TODO: add default attributes
Item::Item (std::string type, int id, BoundingBox bbox, Attributes attributes) :
    type_(type), 
    id_(id), 
    bbox_(bbox),
    attrs_(attributes)
{
    // {{"-lstyle", "-fcolour", "-lcolour", "-lwidth", "-angle", "-sideCount"}}},
    initAbsentAttrs("-lstyle", Value(std::string("straight")));
    initAbsentAttrs("-angle", Value(0));
    initAbsentAttrs("-fcolour", Value(std::string("black")));
    initAbsentAttrs("-lcolour", Value(std::string("green")));
    initAbsentAttrs("-lwidth", Value(1));
    initAbsentAttrs("-text", Value(std::string("")));

    if (type == std::string("polygon")) { 
        initAbsentAttrs("-sideCount", Value(3));
    }
} 

void Item::initAbsentAttrs(Key key, Value val) {
    if (attrs_.getValue(key) == Value()) {
        attrs_.setPair(key, val);
    }
}

void Item::accept(IItemVisitor& visitor) {
    visitor.visitItem(*this);
}

void Item::setBoundingBox(BoundingBox bbox) {
    bbox_ = bbox;
}

BoundingBox Item::getBoundingBox() const {
    return bbox_;
}

int Item::getID() const {
    return id_;
}

std::string Item::getType() const {
    return type_;
}

void Item::setType(std::string type) {
    type_ = type;
}

///TODO: fix this
Value Item::getAttribute(Key key) const { 
    if (attrs_.getValue(key) != Value())  
        return attrs_.getValue(key);
    throw Exception("Attribute not found");
}

void Item::setAttribute(Key key, Value value) {
    attrs_.setPair(key, value);
}

Attributes Item::getAttributes() const {
    return attrs_;
}

///TODO: review this func
void Item::setAttributes(Attributes attrs) {
    for (const auto& pair : attrs) {
        const auto& key = pair.first;
        const auto& val = pair.second;
        attrs_.setPair(key, val);
    }
}

/*for (const auto& pair : attrs) {
    const auto& key = attrs_.getKey(pair.second);
    attrs_.setPair(key, val);
}*/