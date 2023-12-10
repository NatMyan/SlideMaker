#include "Document.hpp"

Document::Document() :
    orientation_("landscape")
{
    slides_.push_back(std::make_shared<Slide>());
}

int Document::addSlide(std::shared_ptr<Slide> slidePtr) {
    slides_.push_back(slidePtr);
}

void Document::insertSlide(std::shared_ptr<Slide> slidePtr, int idx) {
    slides_.insert(slides_.begin(), slidePtr);
}

void Document::removeSlide(int idx) {
    slides_.erase(slides_.begin() + idx);
}

std::shared_ptr<Slide> Document::getSlide(int idx) const {
    if (idx < slides_.size()) {
        return slides_.at(idx);
    }
    return {};
}

size_t Document::getSlideCount() const {
    return slides_.size() - 1;
}

std::pair<std::string, std::pair<double, double> > Document::getFormatSize() {
    return currFormat_;
}

std::pair<double, double> Document::setFormatSize(const std::string& formatName) {
    auto formatSize_ = std::make_unique<FormatSize>();
    currFormat_ = formatSize_->createFormatSize(formatName);
}

std::string Document::setCustomFormatSize(std::pair<double, double> customSize) {
    currFormat_ = {"custom", customSize};
}

std::string Document::getOrientation() const {
    return orientation_;
}

void Document::setOrientation(const std::string& orientation) {
    orientation_ = orientation;
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