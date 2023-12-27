#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "IItem.hpp"
#include "Item.hpp"
#include "IItemVisitor.hpp"
#include "Attributes.hpp"

#include <string>

namespace dat {

class ItemGroup : public IItem {
    struct InvalidAttributeException : public Exception { using Exception::Exception; };

    public:
        using item_iterator = std::vector<std::shared_ptr<Item> >::iterator;
        using const_item_iterator = std::vector<std::shared_ptr<Item> >::const_iterator;

    public:
        ItemGroup() = default;
        explicit ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);
        explicit ItemGroup(int id, BoundingBox bbox, Attributes attrs);

    public:
        void accept(std::shared_ptr<IItemVisitor> visitor);

        void addItem(std::shared_ptr<Item> itemPtr);
        void insertItem(std::shared_ptr<Item> itemPtr, int index); // items_.insert(items_.begin(), itemPtr);
        void removeItem(int id);

        int getID() const override;

        BoundingBox getBoundingBox() const override;
        void setBoundingBox(const BoundingBox& bbox) override;
        
        Value getAttribute(const Key& key) const override;
        void setAttribute(const Key& key, const Value& value) override;

        Attributes getAttributes() const override;
        void setAttributes(const Attributes& attrs) override;

        std::string getType() override;
        void setType(const std::string& type) override; // change all the types into 1 type

        std::shared_ptr<Item> getItem(int id) const;
        size_t getItemCount();

        item_iterator begin();
        item_iterator end();

        const_item_iterator begin() const;
        const_item_iterator end() const;

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

}

#endif // ITEM_GROUPP_HPP