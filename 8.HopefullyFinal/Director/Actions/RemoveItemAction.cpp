#include "RemoveItemAction.hpp"
#include "AddItemAction.hpp"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Slide> slidePtr, int itemID) :
    slidePtr_(slidePtr),
    itemID_(itemID)
{}

void RemoveItemAction::doAction() {
    slidePtr_->removeItem(itemID_);
}

std::shared_ptr<IAction> RemoveItemAction::createReverseAction() {
    return std::make_shared<AddItemAction>(slidePtr_, slidePtr_->getItem(itemID_));
}