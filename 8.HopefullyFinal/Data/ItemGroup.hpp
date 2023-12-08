#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "ItemBase.hpp"
#include "Attributes.hpp"

#include <string>

class ItemGroup : public ItemBase {
    public:
        using ItemIterator = std::vector<std::shared_ptr<ItemBase> >::iterator;

    public:
        ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);

    public:
        void addItem(std::shared_ptr<ItemBase> itemPtr);
        void removeItem(int id);

        int getID() const;
        // void setID(int id);

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox bbox);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);

        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);

        void setType(std::string type); // change all the types into 1 type

        std::shared_ptr<ItemBase> getItem(int id) const;
        std::shared_ptr<ItemBase> getTopItem() const;
        size_t getItemCount();

        ItemIterator begin();
        ItemIterator end();

        // std::string getTypes() const;
        // void setType(std::string type);

    private:
        std::vector<std::shared_ptr<ItemBase> > items_;
        std::string type_;
        int id_; 
        BoundingBox bbox_; 
        Attributes attrs_;
};

#endif // ITEM_GROUPP_HPP