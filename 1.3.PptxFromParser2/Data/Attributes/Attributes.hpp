#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include "AttributesIterator.hpp"

#include <string>

class Attributes {
    public: 
        Attributes (MapPair<Key, Value> mapPairs);

    public:
        Key getKey(const Value& value) const;
        // void setKey(Value value);  
        Value getValue(const Key& key) const;
        // void setValue(Key key);
        ///TODO: are setKey, setValue, getValue needed ?
        void setPair(Key, Value);
        AttributesIterator begin();
        AttributesIterator end();
    
    private:
        bool isPairAttribute(std::pair<Key, Value> pair);

    private:
        MapPair<Key, Value> attributeMap_;   
        std::vector<std::string> attrRegistry_ = { "-lstyle", "-fcolour", "-lcolour", "-lwidth" };
};

#endif // ATTRIBUTES_HPP