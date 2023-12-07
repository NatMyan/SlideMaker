#ifndef ATTRIBUTESS_HPP
#define ATTRIBUTESS_HPP

#include "../definitions.hpp"

class Attributes {
    ///NOTE: let's just pretend this isn't Map's iterator, but a custom one
    using AttributesIterator = Map::iterator; 
    public: 
        Attributes (const Map& info);
 
    public:
        ///TODO: setKey, setValue needed ?
        Key getKey(const Value& value) const;
        Value getValue(const Key& key) const;
        void setPair(Key, Value);
        
        AttributesIterator begin();
        AttributesIterator end();
        // void setKey(Value value);  
        // void setValue(Key key);
        // std::pair<Key, Value> getPair();
    
    private:
        bool isPairAttribute(std::pair<Key, Value> pair);

    private:
        Map attributeMap_;   
};


#endif // ATTRIBUTESS_HPP