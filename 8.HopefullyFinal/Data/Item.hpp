#ifndef ITEMM_LEAF_HPP
#define ITEMM_LEAF_HPP

#include "Attributes.hpp"
#include "ItemInterface.hpp"
#include "IItemVisitor.hpp"

class Item : public ItemInterface {        
    public:
        Item (std::string type, int id, BoundingBox bbox, Attributes attributes);

    public:
        void accept(IItemVisitor& visitor);

        int getID() const override;

        std::string getType() const;
        void setType(std::string type);

        BoundingBox getBoundingBox() const override;
        void setBoundingBox(BoundingBox bbox) override;
        
        Value getAttribute(Key key) const override;
        void setAttribute(Key key, Value value) override;
        
        Attributes getAttributes() const override;
        void setAttributes(Attributes attrs) override;
    
    private:
        void initAbsentAttrs(Key key, Value val);

    private:
        int id_;
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;
};

#endif // ITEMM_LEAF_HPP