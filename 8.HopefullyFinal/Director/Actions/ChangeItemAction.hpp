#ifndef CHANGE_ITEM_ACTION_HPP
#define CHANGE_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"
#include "../../Data/Item.hpp"

class ChangeItemAction : public IAction {
    public:
        ChangeItemAction(std::shared_ptr<Item> itemPtr, Map info);
        ChangeItemAction(std::shared_ptr<ItemGroup> itemGroupPtr, Map info);
    
    public:
        void doAction();
        std::shared_ptr<IAction> createReverseAction();
    
    private:
        void changeItemStuff(std::shared_ptr<ItemBase> itemBasePtr, Map info);
        void getItemStuff(std::shared_ptr<ItemBase> itemBasePtr);
        void getOriginalItemStuff();

    private:    
        std::shared_ptr<ItemGroup> itemGroupPtr_;
        std::shared_ptr<Item> itemPtr_;
        std::shared_ptr<ItemGroup> itemGroupPtrOriginal_;
        std::shared_ptr<Item> itemPtrOriginal_;
        Map info_;
        Map oldInfo_;
};

#endif // CHANGE_ITEM_ACTION_HPP