#include "Item.hpp"
#include "../Attributes/AttributeNotFoundException.hpp"

///TODO: add default attributes
Item::Item (Type type, ID id, Position pos,  Attributes attributes) :
    type_(type), id_(id), pos_(pos), attrs_(attributes)
{} 

void Item::setPosition(Position pos) {
    pos_ = pos;
}

Position Item::getPosition() const {
    return pos_;
}

ID Item::getID() const {
    return id_;
}

Type Item::getType() const {
    return type_;
}

Value Item::getAttribute(Key key) const { 
    if (attrs_.getValue(key) != Value())  
    ///TODO: is this^ correct ?
        return attrs_.getValue(key);
    throw AttributeNotFoundException("Attribute not found");
}

void Item::setAttribute(Key key, Value value) {
    attrs_.setPair(key, value);
}

Attributes Item::getAttributes() const {
    return attrs_;
}

///TODO: review this func
void Item::setAttributes(Attributes attrs) {
    for (const auto& val : attrs) {
        const auto& key = attrs_.getKey(val);
        attrs_.setPair(key, val);
    }
}
