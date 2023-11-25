#include "Slide.hpp"

SlideType<std::shared_ptr<Item> > Slide::getSlide() {
    return slide_;
}

void Slide::addtoSlide(std::shared_ptr<Item> itemPtr) {
    slide_.push_back(itemPtr);
}

void Slide::removeFromSlide(ID id) {
    for (size_t i = 0; i < slide_.size(); ++i) {
        auto itemId = slide_.at(i)->getID();
        if (itemId == id) {
            slide_.erase(slide_.begin() + i);
        }
    } 
}

std::shared_ptr<Item> Slide::getItem(ID id) {
    for (size_t i = 0; i < slide_.size(); ++i) {
        auto itemId = slide_.at(i)->getID();
        if (itemId == id) {
            return slide_.at(i);
        }
    } 
    return nullptr;
}

Slide::SlideIterator Slide::begin() {
    return slide_.begin();
}

Slide::SlideIterator Slide::end() {
    return slide_.end();
}