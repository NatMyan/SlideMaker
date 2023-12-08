#ifndef ADD_ITEM_ACTION_HPP
#define ADD_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"

class AddItemAction : public IAction {
    public:
        AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<ItemBase> itemPtr);
    
    public:
        void doAction();
    
    private:
        std::shared_ptr<Slide> slidePtr_;
        std::shared_ptr<ItemBase> itemPtr_;
};

#endif // ADD_ITEM_ACTION_HPP