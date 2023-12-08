#include "AddItemAction.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<ItemBase> itemPtr) :
    slidePtr_(slidePtr),
    itemPtr_(itemPtr)
{}

void AddItemAction::doAction() {
    slidePtr_->addItem(itemPtr_);
}

std::shared_ptr<Slide> AddItemAction::getSlidePtr() {
    return slidePtr_;
}

std::shared_ptr<ItemBase> AddItemAction::getItemPtr() {
    return itemPtr_;
}