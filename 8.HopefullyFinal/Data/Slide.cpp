#include "Slide.hpp"

void Slide::addItem(std::shared_ptr<ItemBase> itemPtr) {
    itemGroup_->addItem(itemPtr);
    // slide_.push_back(itemPtr);
}

void Slide::insertItem(std::shared_ptr<ItemBase> itemPtr, int index) {
    itemGroup_->insertItem(itemPtr, index);
}

void Slide::removeItem(int id) {
    itemGroup_->removeItem(id);
}

std::shared_ptr<ItemBase> Slide::getItem(int id) {
    return itemGroup_->getItem(id);
}

std::shared_ptr<ItemBase> Slide::getTopItem() {
    return itemGroup_->getTopItem();    
}

std::shared_ptr<ItemBase> Slide::getItemGroup() {
    return itemGroup_;
}

size_t Slide::getItemCount() {
    return itemGroup_->getItemCount();
}

ItemGroup::ItemIterator Slide::begin() {
    return itemGroup_->begin();
    // return slide_.begin();
}

ItemGroup::ItemIterator Slide::end() {
    return itemGroup_->end();
    // return slide_.end();
}


//remove
/*for (size_t i = 0; i < slide_.size(); ++i) {
    auto itemId = slide_.at(i)->getID();
    if (itemId == id) {
        slide_.erase(slide_.begin() + i);
    }
}*/

//get
/*for (size_t i = 0; i < slide_.size(); ++i) {
    auto itemId = slide_.at(i)->getID();
    if (itemId == id) {
        return slide_.at(i);
    }
}
return nullptr; */