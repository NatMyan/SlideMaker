#ifndef I_ITEM_VISITOR_HPP
#define I_ITEM_VISITOR_HPP

#include <memory>

class Item;
class ItemGroup;

class IItemVisitor {
    public:
        virtual void visitItem(const std::unique_ptr<Item> element) const = 0;
        virtual void visitItemGroup(const std::unique_ptr<ItemGroup> element) const = 0;
};

#endif // I_ITEM_VISITOR_HPP