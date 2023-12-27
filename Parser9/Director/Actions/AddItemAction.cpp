#include "AddItemAction.hpp"
#include "RemoveItemAction.hpp"
#include "../../Data/Item.hpp"

namespace dir {

AddItemAction::AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<Item> itemPtr) :
    slidePtr_(slidePtr),
    itemPtr_(itemPtr)
{}

std::shared_ptr<IAction> AddItemAction::doAction() {
    slidePtr_->addItem(itemPtr_);
    return std::make_shared<RemoveItemAction>(slidePtr_, itemPtr_->getID());
}

}