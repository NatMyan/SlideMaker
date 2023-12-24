#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "ItemInterface.hpp"
#include "Item.hpp"
#include "Attributes.hpp"

#include <string>

class ItemGroup : public ItemInterface {
    public:
        using ItemIterator = std::vector<std::shared_ptr<Item> >::iterator;

    public:
        ItemGroup() = default;
        ItemGroup(int id, BoundingBox bbox);
        ItemGroup(int id, BoundingBox bbox, Attributes attrs);
        ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);

    public:
        void accept(IItemVisitor& visitor);

        void addItem(std::shared_ptr<Item> itemPtr);
        void insertItem(std::shared_ptr<Item> itemPtr, int index); // items_.insert(items_.begin(), itemPtr);
        void removeItem(int id);

        int getID() const override;
        // void setID(int id);

        BoundingBox getBoundingBox() const override;
        void setBoundingBox(BoundingBox bbox) override;
        
        Value getAttribute(Key key) const override;
        void setAttribute(Key key, Value value) override;

        Attributes getAttributes() const override;
        void setAttributes(Attributes attrs) override;

        // std::string getType() const override;
        // void setType(std::string type); // change all the types into 1 type

        std::shared_ptr<Item> getItem(int id) const;
        std::shared_ptr<Item> getTopItem() const;
        size_t getItemCount();

        ItemIterator begin();
        ItemIterator end();

        // std::string getTypes() const;
        // void setType(std::string type);
    
    private:
        void updateBoundingBox(const BoundingBox& bbox);
        void initAbsentAttrs(Key key, Value val);
        void setAbsentAttrs();

    private:
        std::vector<std::shared_ptr<Item> > items_;
        std::string type_; // for the case when all the types are the same or that it's itemGroup
        int id_; 
        BoundingBox bbox_; 
        Attributes attrs_;
        std::unordered_map<Key, bool> attrStates_;
};

#endif // ITEM_GROUPP_HPP