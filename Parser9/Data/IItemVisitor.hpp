#ifndef I_ITEM_VISITOR_HPP
#define I_ITEM_VISITOR_HPP

#include <memory>

namespace dat {

class Item;
class ItemGroup;

class IItemVisitor {
    public:
        virtual ~IItemVisitor() = default;
        virtual void visitItem(const Item& item) = 0;
        virtual void visitItemGroup(const ItemGroup& itemGroup) = 0;
};

}

#endif // I_ITEM_VISITOR_HPP