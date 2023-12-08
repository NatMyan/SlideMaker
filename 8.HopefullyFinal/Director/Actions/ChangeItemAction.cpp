#include "ChangeItemAction.hpp"

ChangeItemAction::ChangeItemAction(std::shared_ptr<Item> itemPtr, Map info) :
    itemPtr_(itemPtr),
    itemGroupPtr_(nullptr),
    info_(info)
{}

ChangeItemAction::ChangeItemAction(std::shared_ptr<ItemGroup> itemGroupPtr, Map info) :
    itemGroupPtr_(itemGroupPtr),
    itemPtr_(nullptr),
    info_(info)
{}

void ChangeItemAction::doAction() {
    if (itemPtr_ && !itemGroupPtr_) {
        if ()
    }
    else if (itemGroupPtr_ && !itemPtr_) {
        
    }
}

/*
std::shared_ptr<ItemGroup> itemGroupPtr_;
std::shared_ptr<Item> itemPtr_;
std::string type_;
BoundingBox bbox_;
Attributes attrs_;
*/