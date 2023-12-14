#include "ChangeItemAction.hpp"

ChangeItemAction::ChangeItemAction(std::shared_ptr<Item> itemPtr, Map info) :
    itemPtr_(itemPtr),
    itemPtrOriginal_(itemPtr),
    itemGroupPtr_(nullptr),
    itemGroupPtrOriginal_(nullptr),
    info_(info),
    oldInfo_()
{}

ChangeItemAction::ChangeItemAction(std::shared_ptr<ItemGroup> itemGroupPtr, Map info) :
    itemGroupPtr_(itemGroupPtr),
    itemGroupPtrOriginal_(itemGroupPtr),
    itemPtr_(nullptr),
    itemPtrOriginal_(nullptr),
    info_(info),
    oldInfo_()
{}

void ChangeItemAction::doAction() {
    if (itemPtr_ && !itemGroupPtr_) {
        changeItemStuff(itemPtr_, info_);
    }
    else if (itemGroupPtr_ && !itemPtr_) {
        changeItemStuff(itemGroupPtr_, info_);
    }
}

std::shared_ptr<IAction> ChangeItemAction::createReverseAction() {
    getOriginalItemStuff();
    if (itemPtr_ && !itemGroupPtr_) {
        return std::make_shared<ChangeItemAction>(itemPtrOriginal_, oldInfo_);
    }
    else if (itemGroupPtr_ && !itemPtr_) {
        return std::make_shared<ChangeItemAction>(itemGroupPtrOriginal_, oldInfo_);
    }
    return std::make_shared<IAction>(); // theoretically, it shouldn't come here
}

void ChangeItemAction::getOriginalItemStuff() {
    if (itemPtrOriginal_ && !itemGroupPtrOriginal_) {
        getItemStuff(itemPtrOriginal_);
    }
    else if (itemGroupPtrOriginal_ && !itemPtrOriginal_) {
        getItemStuff(itemGroupPtrOriginal_);
    }
}

///NOTE: I know this isn't ideal, and it probably should be in Change Command, but for now, it should do
void ChangeItemAction::changeItemStuff(std::shared_ptr<ItemBase> itemBasePtr, Map info) {
    for (const auto& pair : info) {
        const auto key = pair.first;
        const auto value = pair.second;
        if (key == "-l" || key == "-t" || key == "-r" || key == "-b") {
            auto bbox = itemBasePtr->getBoundingBox();
            if (key == "-l") { bbox.first.first = defs::toDouble(info["-l"]); }
            if (key == "-t") { bbox.first.second = defs::toDouble(info["-t"]); }
            if (key == "-r") { bbox.second.first = defs::toDouble(info["-r"]); }
            if (key == "-b") { bbox.second.second = defs::toDouble(info["-b"]); }
            itemBasePtr->setBoundingBox(bbox);
        }
        else {
            itemBasePtr->setAttribute(key, value);
        }
    }
}

void ChangeItemAction::getItemStuff(std::shared_ptr<ItemBase> itemBasePtr) {
    for (const auto& pair : info_) {
        const Key key = pair.first;
        Value value = pair.second;
        // if (key == "-type") {
            // value = Value(itemBasePtr->getType());
        // }
        if (key == "-l" || key == "-t" || key == "-r" || key == "-b") {
            auto bbox = itemBasePtr->getBoundingBox();
            if (key == "-l") { value = Value(itemBasePtr->getBoundingBox().first.first); }
            if (key == "-t") { value = Value(itemBasePtr->getBoundingBox().first.second); }
            if (key == "-r") { value = Value(itemBasePtr->getBoundingBox().second.first); }
            if (key == "-b") { value = Value(itemBasePtr->getBoundingBox().second.second); }
        }
        else {
            value = itemBasePtr->getAttribute(key);
        }
        oldInfo_[key] = value;
    }
}

/*
std::shared_ptr<ItemGroup> itemGroupPtr_;
std::shared_ptr<Item> itemPtr_;
std::string type_;
BoundingBox bbox_;
Attributes attrs_;
*/