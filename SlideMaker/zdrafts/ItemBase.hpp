/*#ifndef ITEM_BASE_HPP
#define ITEM_BASE_HPP

#include "IItemVisitor.hpp"
#include "ItemInterface.hpp"

class ItemBase : public ItemInterface {    
    public:
        ItemBase (int id, BoundingBox bbox, Attributes attributes);
        
    public:
        int getID() const override final;

        BoundingBox getBoundingBox() const override;
        void setBoundingBox(BoundingBox bbox) override;

        Value getAttribute(Key key) const override final;
        void setAttribute(Key key, Value value) override final;

        Attributes getAttributes() const override final;
        void setAttributes(Attributes attrs) override final;

    protected:
        int id_;
        BoundingBox bbox_;
        Attributes attrs_;
};

#endif // ITEM_BASE_HPP*/