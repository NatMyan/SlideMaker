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
        changeItemStuff(itemPtr_);
    }
    else if (itemGroupPtr_ && !itemPtr_) {
        changeItemStuff(itemGroupPtr_);
    }
}

void ChangeItemAction::changeItemStuff(std::shared_ptr<ItemBase> itemBasePtr) {
    for (const auto& pair : info_) {
        const auto key = pair.first;
        const auto value = pair.second;
        if (key == "-type") {
            itemBasePtr->setType(defs::toStr(info_["-type"]));
        }
        if (key == "-l" || key == "-t" || key == "-r" || key == "-b") {
            auto bbox = itemBasePtr->getBoundingBox();
            if (key == "-l") { bbox.first.first = defs::toDouble(info_["-l"]); }
            if (key == "-t") { bbox.first.second = defs::toDouble(info_["-t"]); }
            if (key == "-r") { bbox.second.first = defs::toDouble(info_["-r"]); }
            if (key == "-b") { bbox.second.second = defs::toDouble(info_["-b"]); }
            itemBasePtr->setBoundingBox(bbox);
        }
        else {
            itemBasePtr->setAttribute(key, value);
        }
    }
}

/*
std::shared_ptr<ItemGroup> itemGroupPtr_;
std::shared_ptr<Item> itemPtr_;
std::string type_;
BoundingBox bbox_;
Attributes attrs_;
*/