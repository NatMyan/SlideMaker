#include "RemoveItemAction.hpp"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Slide> slide, int itemID) :
    slide_(slide),
    itemID_(itemID)
{}

void RemoveItemAction::doAction() {
    slide_->removeItem(itemID_);
}
