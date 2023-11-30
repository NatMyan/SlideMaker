#include "Item.hpp"
#include "../../Exception.hpp"

///TODO: add default attributes
Item::Item (Type type, ID id, Position pos,  Attributes attributes) :
    type_(type), 
    id_(id), 
    pos_(pos),
    attrs_(attributes)
{
    // {{"-lstyle", "-fcolour", "-lcolour", "-lwidth", "-down", "-sideCount"}}},
    if (attrs_.getValue("-lstyle") == Value()) {
        attrs_.setPair("-lstyle", Value(std::string("straight")));
    }
    if (attrs_.getValue("-fcolour") == Value()) {
        attrs_.setPair("-fcolour", Value(std::string("black")));
    }
    if (attrs_.getValue("-lcolour") == Value()) {
        attrs_.setPair("-lcolour", Value(std::string("green")));
    }
    if (attrs_.getValue("-lwidth") == Value()) {
        attrs_.setPair("-lwidth", Value(1));
    }
    if (type == std::string("polygon") && attrs_.getValue("-sideCount") == Value()) {
        attrs_.setPair("-sideCount", Value(5));
    }
} 

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

void Item::setType(Type type) {
    type_ = type;
}

Value Item::getAttribute(Key key) const { 
    if (attrs_.getValue(key) != Value())  
    ///TODO: is this^ correct ?
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
    for (const auto& val : attrs) {
        const auto& key = attrs_.getKey(val);
        attrs_.setPair(key, val);
    }
}
