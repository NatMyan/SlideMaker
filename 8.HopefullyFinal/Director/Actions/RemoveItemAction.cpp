#include "RemoveItemAction.hpp"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Slide> slidePtr, int itemID) :
    slidePtr_(slidePtr),
    itemID_(itemID)
{}

void RemoveItemAction::doAction() {
    slidePtr_->removeItem(itemID_);
}

