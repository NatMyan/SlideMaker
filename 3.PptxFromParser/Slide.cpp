#include "Slide.hpp"

SlideType<ID, std::shared_ptr<Item> > Slide::getSlide() {
    return slide_;
}

void Slide::addtoSlide(std::shared_ptr<Item> item) {
    slide_.push_back(TupleWrapper{item->getID(), item});
}

void Slide::removeFromSlide(ID id) {
    for (auto it = slide_.begin(); it != slide_.end(); ++it) {
        if (it->get<0>() == id) {
            it = slide_.erase(it);
        }
    }
}

std::shared_ptr<Item> Slide::getItem(ID id) {
    auto it = slide_.begin();
    while (it != slide_.end()) {
        if (it->get<0>() == id) {
            return it->get<1>();
        }
        ++it;
    }
    return it->get<1>(); 
    ///NOTE: this^ should be the end
}

Slide::SlideIterator Slide::begin() {
    return slide_.begin();
}

Slide::SlideIterator Slide::end() {
    return slide_.end();
}