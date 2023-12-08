#include "Document.hpp"

Document::Document() {
    slides_.push_back(std::make_shared<Slide>());
}

int Document::addSlide(std::shared_ptr<Slide> slidePtr) {
    slides_.push_back(slidePtr);
}

void Document::removeSlide(int idx) {
    slides_.erase(slides_.begin() + idx);
}

std::shared_ptr<Slide> Document::getSlide(int idx) {
    if (idx < slides_.size()) {
        return slides_.at(idx);
    }
    return {};
}

size_t Document::getSlideCount() {
    return slides_.size() - 1;
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