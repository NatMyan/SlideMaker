#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "ItemBase.hpp"
#include "Attributes.hpp"

#include <string>

class ItemGroup : public ItemBase {
    public:
        using ItemIterator = std::vector<std::shared_ptr<Item> >::iterator;

    public:
        ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);

    public:
        void accept(std::unique_ptr<IItemVisitor> visitor);

        void addItem(std::shared_ptr<Item> itemPtr);
        void insertItem(std::shared_ptr<Item> itemPtr, int index); // items_.insert(items_.begin(), itemPtr);
        void removeItem(int id);

        int getID() const;
        // void setID(int id);

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox bbox);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);

        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);

        std::string getType() const;
        void setType(std::string type); // change all the types into 1 type

        std::shared_ptr<Item> getItem(int id) const;
        std::shared_ptr<Item> getTopItem() const;
        size_t getItemCount();

        ItemIterator begin();
        ItemIterator end();

        // std::string getTypes() const;
        // void setType(std::string type);

    private:
        std::vector<std::shared_ptr<Item> > items_;
        std::string type_; // for the case when all the types are the same or that it's itemGroup
        int id_; 
        BoundingBox bbox_; 
        Attributes attrs_;
};

#endif // ITEM_GROUPP_HPP