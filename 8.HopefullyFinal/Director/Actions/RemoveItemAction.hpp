#ifndef REMOVE_ITEM_ACTION_HPP
#define REMOVE_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"

class RemoveItemAction : public IAction {
    public:
        RemoveItemAction(std::shared_ptr<Slide> slidePtr, int itemID);
    
    public:
        void doAction();
        std::shared_ptr<Slide> getSlidePtr();
        int getItemID();
    
    private:
        std::shared_ptr<Slide> slidePtr_;
        int itemID_;
};

#endif // REMOVE_ITEM_ACTION_HPP