#include "Director.hpp"

Director::Director() :
    actions_(),
    currPosIter_(actions_.begin())
{}

void Director::runAction(std::shared_ptr<IAction> action) {
    action = action->doAction();

    ///TODO: revisit to the end() iter
    if (!actions_.empty() && currPosIter_ != std::prev(actions_.end())) {
        actions_.erase(currPosIter_, actions_.end());
    }
    actions_.push_back(action);
    currPosIter_ = std::prev(actions_.end());
    if (actions_.size() >= maxCount_) {
        actions_.pop_front();
    }
    // --currPosIter_; // to point at the last valid element
}

void Director::undo() {
    if (currPosIter_ != actions_.begin()) {
        --currPosIter_;
        // *currPosIter_ = (*currPosIter_)->createReverseAction();
        *currPosIter_ = (*currPosIter_)->doAction();
    }
}

void Director::redo() {
    if (!actions_.empty() && currPosIter_ != std::prev(actions_.end())) { // end() points to the one after the last element
        ++currPosIter_;
        // *currPosIter_ = (*currPosIter_)->createReverseAction();
        *currPosIter_ = (*currPosIter_)->doAction();
    }
}


/*if (undoCount_ <= maxCount_ && undoCount_ != 0) {
    actions_
}*/