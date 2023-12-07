#include "Document.hpp"

Document::Document() {
    slides_.push_back(std::make_shared<Slide>());
}

void Document::addSlide(std::shared_ptr<Slide> slidePtr) {
    slides_.push_back(slidePtr);
}

void Document::removeSlide(int idx) {
    slides_.erase(slides_.begin() + idx);
}

std::weak_ptr<Slide> Document::getSlide(int idx) {
    if (idx < slides_.size()) {
        return slides_.at(idx);
    }
    return {};
}

Document::SlideIterator Document::begin() {
    return slides_.begin();
}

Document::SlideIterator Document::end() {
    return slides_.end();
}

///TODO: probably improve this when time allows + have this or nah ?
/*Document::Document (int slideNum) {
    for (size_t i = 0; i < slideNum; ++i) {
        slides_.push_back(std::make_shared<Slide>());
    }
}*/