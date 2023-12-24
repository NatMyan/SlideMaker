#ifndef ITEM_INTERFACE_HPP
#define ITEM_INTERFACE_HPP

#include "../definitions.hpp"
#include "Attributes.hpp"

class ItemInterface {
    public:
        virtual ~ItemInterface() = default;
        virtual int getID() const = 0;
        // virtual std::string getType() const = 0;
        
        virtual BoundingBox getBoundingBox() const = 0;
        virtual void setBoundingBox(BoundingBox bbox) = 0;

        virtual Value getAttribute(Key key) const = 0;
        virtual void setAttribute(Key key, Value value) = 0;

        virtual Attributes getAttributes() const = 0;
        virtual void setAttributes(Attributes attrs) = 0;
};

#endif // ITEM_INTERFACE_HPP