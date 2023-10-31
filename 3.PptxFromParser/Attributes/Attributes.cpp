#include "Attributes.hpp"

#include <algorithm>

Attributes::Attributes(MapPair<Key, Value> mapPairs) {
    for (auto pair : mapPairs) {
        if (isPairAttribute(pair)) {
            attributeMap_[pair.first] = pair.second;
        }
    }
}

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

bool Attributes::isPairAttribute(std::pair<Key, Value> p) {
    return (std::binary_search(attrRegistry_.begin(), attrRegistry_.end(), p.first));
    /*return (p.first != "-type" && p.first != "-t" && p.first != "-l" && p.first != "-b" && p.first != "-r"
            && p.first != "-w" && p.first != "-h" && p.first != "-x" && p.first != "-y");*/
}