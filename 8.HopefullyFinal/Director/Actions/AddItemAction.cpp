#include "AddItemAction.hpp"
#include "RemoveItemAction.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<ItemBase> itemPtr) :
    slidePtr_(slidePtr),
    itemPtr_(itemPtr)
{}

void AddItemAction::doAction() {
    slidePtr_->addItem(itemPtr_);
}

std::shared_ptr<IAction> AddItemAction::createReverseAction() {
    return std::make_shared<RemoveItemAction>(slidePtr_, itemPtr_->getID());
}