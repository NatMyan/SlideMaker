#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "ItemBase.hpp"
#include "Attributes.hpp"

#include <string>

class ItemGroup {
    public:
        using ItemIterator = std::vector<std::shared_ptr<ItemBase> >::iterator;

    public:
        ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);

    public:
        void addItem(std::shared_ptr<ItemBase> itemPtr);
        
        int getGroupId();
        void setGroupId(int id);

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox bbox);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);

        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);

        std::shared_ptr<ItemBase> getItem(int id);
        std::shared_ptr<ItemBase> getTopItem();

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