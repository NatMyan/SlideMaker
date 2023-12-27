#include "Item.hpp"

namespace dat {

explicit Item::Item (std::string type, int id, BoundingBox bbox, Attributes attributes) :
    type_(type), 
    id_(id), 
    bbox_(bbox),
    attrs_(attributes)
{
    // "-lstyle", "-fcolour", "-lcolour", "-lwidth", "-angle", "-sideCount", "-text", "-tcolour", "-tsize"
    setAbsentAttrs();
} 

void Item::setAbsentAttrs() {
    initAbsentAttrs("-lstyle", Value(std::string("straight")));
    initAbsentAttrs("-angle", Value(0));
    initAbsentAttrs("-fcolour", Value(std::string("green")));
    initAbsentAttrs("-lcolour", Value(std::string("black")));
    initAbsentAttrs("-lwidth", Value(1));
    initAbsentAttrs("-text", Value(std::string("")));
    initAbsentAttrs("-tcolour", Value(std::string("black")));
    initAbsentAttrs("-tsize", Value(12));

    if (type_ == std::string("polygon")) { 
        initAbsentAttrs("-sideCount", Value(3)); 
    }
}

void Item::initAbsentAttrs(const Key& key, const Value& val) {
    try { attrs_.getValue(key); }
    catch (const Exception& e) { attrs_.setPair(key, val); }
}

void Item::accept(std::shared_ptr<IItemVisitor> visitor) {
    visitor->visitItem(*this);
}

void Item::setBoundingBox(const BoundingBox& bbox) {
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

void Item::setType(const std::string& type) {
    type_ = type;
}

Value Item::getAttribute(const Key& key) const { 
    try { return attrs_.getValue(key); }
    catch (const Exception& e) { throw InvalidAttributeException("Attribute not found"); }
}

void Item::setAttribute(const Key& key, const Value& value) {
    attrs_.setPair(key, value);
}

Attributes Item::getAttributes() const {
    return attrs_;
}

void Item::setAttributes(const Attributes& attrs) {
    for (const auto& pair : attrs) {
        attrs_.setPair(pair.first, pair.second);
    }
}

}