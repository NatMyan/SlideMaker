#include "ChangeItemAction.hpp"

ChangeItemAction::ChangeItemAction(std::shared_ptr<ItemGroup> itemGroupPtr, Map info) :
    itemGroupPtr_(itemGroupPtr),
    info_(info)
{}

ChangeItemAction::ChangeItemAction(std::shared_ptr<Item> itemPtr, Map info) :
    itemPtr_(itemPtr),
    info_(info)
{}

void ChangeItemAction::doAction() {
    
}

