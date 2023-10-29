#include "Attributes.hpp"

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

void Attributes::setPair (Key key, Value value) {
    attributeMap_[key] = value;
}

AttributesIterator<Key, Value> Attributes::begin() {
    return AttributesIterator<Key, Value>(attributeMap_.begin()); 
}

AttributesIterator<Key, Value> Attributes::end() {
    return AttributesIterator<Key, Value>(attributeMap_.end());
}
