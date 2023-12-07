#ifndef ATTRIBUTESS_HPP
#define ATTRIBUTESS_HPP

#include "../definitions.hpp"

class Attributes {
    using AttributesIterator = Map::iterator;
    public: 
        Attributes (const Map& info);
 
    public:
        ///TODO: setKey, setValue needed ?
        Key getKey(const Value& value) const;
        // void setKey(Value value);  

        Value getValue(const Key& key) const;
        // void setValue(Key key);

        void setPair(Key, Value);
        std::pair<Key, Value> getPair();

        AttributesIterator begin();
        AttributesIterator end();
    
    private:
        bool isPairAttribute(std::pair<Key, Value> pair);

    private:
        Map attributeMap_;   
};


#endif // ATTRIBUTESS_HPP