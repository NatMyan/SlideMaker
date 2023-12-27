#ifndef I_ITEM_HPP
#define I_ITEM_HPP

#include "Attributes.hpp"
#include "../zhelpers/Definitions.hpp"

namespace dat {

///NOTE: I don't want to have an item base, 'cause of different implementations and the composite pattern. An interface should be enough
class IItem {
    public:
        virtual ~IItem() = default;
        
        virtual ID getID() const = 0;

        virtual std::string getType() const = 0;
        virtual void setType(const std::string& type) = 0;
        
        virtual BoundingBox getBoundingBox() const = 0;
        virtual void setBoundingBox(const BoundingBox& bbox) = 0;

        virtual Value getAttribute(const Key& key) const = 0;
        virtual void setAttribute(const Key& key, const Value& value) = 0;

        virtual Attributes getAttributes() const = 0;
        virtual void setAttributes(const Attributes& attrs) = 0;
};

}

#endif // I_ITEM_HPP