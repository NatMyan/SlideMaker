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
        std::shared_ptr<Slide> getItemGroupPtr();
        std::shared_ptr<ItemBase> getItemPtr();
        Map getInfo();
    
    private:
        void changeItemStuff(std::shared_ptr<ItemBase> itemBasePtr);

    private:    
        std::shared_ptr<ItemGroup> itemGroupPtr_;
        std::shared_ptr<Item> itemPtr_;
        Map info_;
};

#endif // CHANGE_ITEM_ACTION_HPP