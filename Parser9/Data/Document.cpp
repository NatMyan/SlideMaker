#include "Document.hpp"

#include <algorithm>    // std::min, std::max

namespace dat {

Document::Document() :
    orientation_("landscape")
{
    setFormatSize("A4");
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
    return nullptr;
}

std::shared_ptr<Slide> Document::getSlideByItemID(int itemID) const {
    for (auto slide : slides_) {
        if (slide->getItem(itemID)) {
            return slide;
        }
    }
    return nullptr;
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

    auto temp = currFormat_.second;
    if (orientation_ == "landscape") {
        currFormat_.second.first = std::max(temp.first, temp.second);
        currFormat_.second.second = std::min(temp.first, temp.second);
    }
    else if (orientation_ == "portrait") {
        currFormat_.second.first = std::min(temp.first, temp.second);
        currFormat_.second.second = std::max(temp.first, temp.second);
    }
    else {
        throw InvalidOrientationException("Invalid orientation: " + orientation);
    }
}

Document::slide_iterator Document::begin() {
    return slides_.begin();
}

Document::slide_iterator Document::end() {
    return slides_.end();
}

Document::const_slide_iterator Document::begin() const {
    return slides_.cbegin();
}

Document::const_slide_iterator Document::end() const {
    return slides_.cend();
}

}

///TODO: probably improve this when time allows + have this or nah ?
/*Document::Document (int slideNum) {
    for (size_t i = 0; i < slideNum; ++i) {
        slides_.push_back(std::make_shared<Slide>());
    }
}*/