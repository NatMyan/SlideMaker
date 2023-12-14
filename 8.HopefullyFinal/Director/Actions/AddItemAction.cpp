#include "AddItemAction.hpp"
#include "RemoveItemAction.hpp"
#include "../../Data/Item.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<Item> itemPtr) :
    slidePtr_(slidePtr),
    itemPtr_(itemPtr)
{}

void AddItemAction::doAction() {
    slidePtr_->addItem(itemPtr_);
}

std::shared_ptr<IAction> AddItemAction::createReverseAction() {
    return std::make_shared<RemoveItemAction>(slidePtr_, itemPtr_->getID());
}