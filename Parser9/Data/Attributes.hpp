#ifndef ATTRIBUTESS_HPP
#define ATTRIBUTESS_HPP

#include "../zhelpers/Definitions.hpp"
#include "../zhelpers/Exception.hpp"

namespace dat {

class Attributes {
    struct InvalidPairException : public Exception { using Exception::Exception; };

    public:
        using attr_iterator = Map::iterator; 
        using const_attr_iterator = Map::const_iterator;

    public: 
        Attributes() = default;
        Attributes (const Map& info);
 
    public:
        bool operator==(Attributes other);
        bool operator!=(Attributes other);

        Key getKey(const Value& value) const;
        Value getValue(const Key& key) const;
        void setPair(Key, Value);

        attr_iterator begin();
        attr_iterator end();  

        const_attr_iterator begin() const;
        const_attr_iterator end() const;

    private:
        Map attributeMap_;  
};

}

#endif // ATTRIBUTESS_HPP