#ifndef CHANGE_ITEM_ACTION_HPP
#define CHANGE_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"
#include "../../Data/Item.hpp"
#include "../../Data/ItemGroup.hpp"
#include "../../Data/IItemVisitor.hpp"

namespace dir {

class ChangeItemAction : public IAction {
    public:
        ChangeItemAction(std::shared_ptr<Item> itemPtr, Map info);
        ChangeItemAction(std::shared_ptr<ItemGroup> itemGroupPtr, Map info);
    
    public:
        std::shared_ptr<IAction> doAction();
    
    private:
        void changeItemStuff(std::shared_ptr<IItem> itemInterfacePtr, Map info);
        void getItemStuff(std::shared_ptr<IItem> itemInterfacePtr);
        void getOriginalItemStuff();

    private:    
        std::shared_ptr<ItemGroup> itemGroupPtr_;
        std::shared_ptr<Item> itemPtr_;
        std::shared_ptr<ItemGroup> itemGroupPtrOriginal_;
        std::shared_ptr<Item> itemPtrOriginal_;
        Map info_;
        Map oldInfo_;
};

}

#endif // CHANGE_ITEM_ACTION_HPP