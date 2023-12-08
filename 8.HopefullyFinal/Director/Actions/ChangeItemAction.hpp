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

    private:    
        std::shared_ptr<ItemGroup> itemGroupPtr_;
        std::shared_ptr<Item> itemPtr_;
        Map info_;
};

#endif // CHANGE_ITEM_ACTION_HPP