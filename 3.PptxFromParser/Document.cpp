#include "Document.hpp"

Document::Document() {
    slides_.push_back(std::make_shared<Slide>());
}

///TODO: probably improve this when time allows
Document::Document (int slideNum) {
    for (size_t i = 0; i < slideNum; ++i) {
        slides_.push_back(std::make_shared<Slide>());
    }
}

DocumentType<std::shared_ptr<Slide> > Document::getSlides() {
    return slides_;
}

void Document::addtoDocument(std::shared_ptr<Slide> slidePtr) {
    slides_.push_back(slidePtr);
}

void Document::removeFromDocument(Idx idx) {
    slides_.erase(slides_.begin() + idx);
}

std::shared_ptr<Slide> Document::getSlide(Idx idx) {
    if (idx < slides_.size()) {
        return slides_.at(idx);
    }
    return nullptr;
}

Document::DocumentIterator Document::begin() {
    return slides_.begin();
}

Document::DocumentIterator Document::end() {
    return slides_.end();
}