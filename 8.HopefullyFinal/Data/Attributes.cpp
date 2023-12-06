#include "Attributes.hpp"

Attributes::Attributes(const Map& info) :
    attributeMap_(info)
{}

Key Attributes::getKey(const Value& value) const {
    for (const auto& pair : attributeMap_) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return Key();
}

// void Attributes::setKey(Value value) {

// }

Value Attributes::getValue(const Key& key) const {
    auto it = attributeMap_.find(key);
    if (it != attributeMap_.end()) {
        return it->second;
    }
    return Value();
}

// void Attributes::setValue(Key key) {

// }

void Attributes::setPair(Key, Value) {
    attributeMap_[key] = value;
}

std::Attributes::pair<Key, Value> getPair() {
    // attributeMap_[key] = value;
}

Attributes::AttributesIterator Attributes::begin() {
    return AttributesIterator(attributeMap_.begin()); 
}

Attributes::AttributesIterator Attributes::end() {
    return AttributesIterator(attributeMap_.begin()); 
}