#include "RemoveItemAction.hpp"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Slide> slidePtr, int itemID) :
    slidePtr_(slidePtr),
    itemID_(itemID)
{}

void RemoveItemAction::doAction() {
    slidePtr_->removeItem(itemID_);
}

std::shared_ptr<Slide> RemoveItemAction::getSlidePtr() {
    return slidePtr_;
}

int RemoveItemAction::getItemID() {
    return itemID_;
}