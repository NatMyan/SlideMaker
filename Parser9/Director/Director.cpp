#include "Director.hpp"
#include "../Application.hpp"

namespace dir {

Director::Director() :
    actions_(),
    currPosIter_(actions_.begin()),
    activeSlide_(app::Application::getApplication()->getDocument()->getSlide(0))
{}

void Director::runAction(std::shared_ptr<IAction> action) {
    action = action->doAction();

    if (!actions_.empty() && currPosIter_ != std::prev(actions_.end())) {
        actions_.erase(currPosIter_, actions_.end());
    }
    actions_.push_back(action);
    currPosIter_ = std::prev(actions_.end());
    if (actions_.size() >= maxCount_) {
        actions_.pop_front();
    }
}

void Director::undo() {
    if (currPosIter_ != actions_.begin()) {
        --currPosIter_;
        *currPosIter_ = (*currPosIter_)->doAction();
    }
}

void Director::redo() {
    if (!actions_.empty() && currPosIter_ != std::prev(actions_.end())) { // end() points to the one after the last element
        ++currPosIter_;
        *currPosIter_ = (*currPosIter_)->doAction();
    }
}

void Director::setActiveSlide(ID idx) {
    activeSlide_ = app::Application::getApplication()->getDocument()->getSlide(idx);
}

ID Director::getActiveSlideIdx() {
    auto doc = app::Application::getApplication()->getDocument();
    auto it = std::find(doc->begin(), doc->end(), activeSlide_);
    if (it != doc->end()) { return std::distance(doc->begin(), it); }
    return -1; // theoretically, it shouldn't reach this point
}

}

/*if (undoCount_ <= maxCount_ && undoCount_ != 0) {
    actions_
}*/