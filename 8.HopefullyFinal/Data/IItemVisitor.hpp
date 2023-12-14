#ifndef I_ITEM_VISITOR_HPP
#define I_ITEM_VISITOR_HPP

#include <memory>

class Item;
class ItemGroup;

class IItemVisitor {
    public:
        virtual void visitItem(std::shared_ptr<Item> element) = 0;
        virtual void visitItemGroup(std::shared_ptr<ItemGroup> element) = 0;
};

#endif // I_ITEM_VISITOR_HPP