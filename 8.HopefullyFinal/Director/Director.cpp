#include "Director.hpp"

Director::Director() :
    actions_(),
    it_(actions_.begin())
{}

void Director::runAction(std::shared_ptr<IAction> action) {
    action->doAction();

    actions_.push_back(action);
    it_ = actions_.end();
    if (actions_.size() >= maxCount_) {
        actions_.pop_front();
    }
    // --it_; // to point at the last valid element
}

void Director::undo() {
    if (it_ != actions_.begin()) {
        --it_;
        *it_ = (*it_)->createReverseAction();
        (*it_)->doAction();
    }
}

void Director::redo() {
    auto lastElemIter = actions_.end();
    --lastElemIter; // to point at the last valid element
    if (it_ != lastElemIter) {
        ++it_;
        *it_ = (*it_)->createReverseAction();
        (*it_)->doAction();
    }
}


/*if (undoCount_ <= maxCount_ && undoCount_ != 0) {
    actions_
}*/