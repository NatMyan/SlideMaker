#include "Slide.hpp"

void Slide::addItem(std::shared_ptr<ItemBase> itemPtr) {
    itemGroup_->addItem(itemPtr);
    // slide_.push_back(itemPtr);
}

void Slide::removeItem(int id) {
    for (size_t i = 0; i < slide_.size(); ++i) {
        auto itemId = slide_.at(i)->getID();
        if (itemId == id) {
            slide_.erase(slide_.begin() + i);
        }
    } 
}

std::shared_ptr<ItemBase> Slide::getItem(int id) {
    for (size_t i = 0; i < slide_.size(); ++i) {
        auto itemId = slide_.at(i)->getID();
        if (itemId == id) {
            return slide_.at(i);
        }
    } 
    return nullptr;
}

Slide::ItemIterator Slide::begin() {
    return slide_.begin();
}

Slide::ItemIterator Slide::end() {
    return slide_.end();
}