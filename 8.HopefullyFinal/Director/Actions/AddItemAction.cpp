#include "AddItemAction.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Slide> slide, std::shared_ptr<ItemBase> itemPtr) :
    slide_(slide),
    itemPtr_(itemPtr)
{}

void AddItemAction::doAction() {
    slide_->addItem(itemPtr_);
}
