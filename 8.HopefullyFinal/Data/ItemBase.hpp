#ifndef ITEM_BASE_HPP
#define ITEM_BASE_HPP

#include "IItemVisitor.hpp"

//TK: ItemBase should be  base class, it should implement common members and methods
//TK: Your hierarchy shoud look like this: Item (interface) <- ItemBase <- ItemLeaf, ItemGroup 

class Item {    
    public:
        //TK: What is this std::unique_ptr for? Do you passing the ownership of the visitor to the Item, really???
        //virtual void accept(std::unique_ptr<IItemVisitor> visitor) = 0; 
        virtual void accept(IItemVisitor& visitor) = 0; 

        virtual ItemId getID() const = 0; //TK: return ItemId instead

        virtual std::string getType() const = 0;
        // virtual void setType(std::string type) = 0;

        virtual BoundingBox getBoundingBox() const = 0;
        virtual void setBoundingBox(BoundingBox bbox) = 0;
        
        virtual Value getAttribute(Key key) const = 0;
        virtual void setAttribute(Key key, Value value) = 0;
        
        virtual Attributes getAttributes() const = 0;
        virtual void setAttributes(Attributes attrs) = 0;
};

class ItemBase : public Item {    
    public:

        ItemId getID() const override final;

        BoundingBox getBoundingBox() const override;
        void setBoundingBox(BoundingBox bbox) override;
        
        Value getAttribute(Key key) const override final;
        void setAttribute(Key key, Value value)override final;
        
        Attributes getAttributes() const override final;
        void setAttributes(Attributes attrs) override final;

protected:
        int id_;
        BoundingBox bbox_;
        Attributes attrs_;
};

#endif // ITEM_BASE_HPP