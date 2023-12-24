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

Value Attributes::getValue(const Key& key) const {
    auto it = attributeMap_.find(key);
    if (it != attributeMap_.end()) {
        return it->second;
    }
    return Value();
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

Attributes::AttributesIterator Attributes::begin() {
    return AttributesIterator(attributeMap_.begin()); 
}

Attributes::AttributesIterator Attributes::end() {
    return AttributesIterator(attributeMap_.end()); 
}


// void Attributes::setKey(Value value) {

// }

// void Attributes::setValue(Key key) {

// }

/*std::pair<Key, Value> Attributes::getPair() {
    return attributeMap_;
    // attributeMap_[key] = value;
}*/