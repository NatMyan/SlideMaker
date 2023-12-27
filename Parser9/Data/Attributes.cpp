#include "Attributes.hpp"

namespace dat {

Attributes::Attributes(const Map& info) :
    attributeMap_(info)
{}

Key Attributes::getKey(const Value& value) const {
    for (const auto& pair : attributeMap_) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    throw InvalidPairException("Key not found for value: " + defs::toStr(value));
    // return Key();
}

Value Attributes::getValue(const Key& key) const {
    auto it = attributeMap_.find(key);
    if (it != attributeMap_.end()) {
        return it->second;
    }
    throw InvalidPairException("Value not found for key: " + key);
    // return Value();
}

void Attributes::setPair(Key key, Value value) {
    attributeMap_[key] = value;
}

bool Attributes::operator==(Attributes other) {
    return *this == other;
}

bool Attributes::operator!=(Attributes other) {
    return *this != other;
}

Attributes::attr_iterator Attributes::begin() {
    return attr_iterator(attributeMap_.begin()); 
}

Attributes::attr_iterator Attributes::end() {
    return attr_iterator(attributeMap_.end()); 
}

Attributes::const_attr_iterator Attributes::begin() const {
    return const_attr_iterator(attributeMap_.cbegin());
}

Attributes::const_attr_iterator Attributes::end() const {
    return const_attr_iterator(attributeMap_.cend());
}

}