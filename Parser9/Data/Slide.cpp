#include "Slide.hpp"

namespace dat {

Slide::Slide() :
    itemGroup_(std::make_shared<ItemGroup>())
{}

void Slide::addItem(std::shared_ptr<Item> itemPtr) {
    itemGroup_->addItem(itemPtr);
}

void Slide::insertItem(std::shared_ptr<Item> itemPtr, int index) {
    itemGroup_->insertItem(itemPtr, index);
}

void Slide::removeItem(int id) {
    itemGroup_->removeItem(id);
}

std::shared_ptr<Item> Slide::getItem(int id) {
    return itemGroup_->getItem(id);
}

std::shared_ptr<ItemGroup> Slide::getItemGroup() {
    return itemGroup_;
}

size_t Slide::getItemCount() {
    return itemGroup_->getItemCount();
}

ItemGroup::item_iterator Slide::begin() {
    return itemGroup_->begin();
}

ItemGroup::item_iterator Slide::end() {
    return itemGroup_->end();
}

ItemGroup::const_item_iterator Slide::begin() const {
    return ItemGroup::const_item_iterator(itemGroup_->begin());
}

ItemGroup::const_item_iterator Slide::end() const {
    return ItemGroup::const_item_iterator(itemGroup_->end());
}

}

/*std::shared_ptr<Item> Slide::getTopItem() {
    return itemGroup_->getTopItem();    
}*/

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