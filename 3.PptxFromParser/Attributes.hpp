#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include "definitions.hpp"
#include "AttributesIterator.hpp"

#include <string>

class Attributes {
    public:
        Key getKey(const Value& value) const;
        // void setKey(Value value);  
        Value getValue(const Key& key) const;
        // void setValue(Key key);
        ///TODO: are setKey, setValue, getValue needed ?
        void setPair(Key, Value);
        AttributesIterator<Key, Value> begin();
        AttributesIterator<Key, Value> end();
    
    private:
        MapPair<Key, Value> attributeMap_;   
};

#endif // ATTRIBUTES_HPP