#ifndef ITEMM_HPP
#define ITEMM_HPP

#include "Attributes.hpp"
#include "ItemBase.hpp"

class Item : public ItemBase {        
    public:
        Item (std::string type, int id, BoundingBox bbox, Attributes attributes);

    public:
        int getID() const;

        std::string getType() const;
        void setType(std::string type);

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox bbox);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);
        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);

    private:
        int id_;
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;
};

#endif // ITEMM_HPP