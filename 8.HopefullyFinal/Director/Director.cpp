#include "Director.hpp"

Director::Director() :
    actions_(),
    it_(actions_.begin())
{}

void Director::runAction(std::shared_ptr<IAction> action) {
    //action->doAction();
    //TK: you should create reverse action then add it to your stack, otherwise your program may not be executed as expected
    //TK: your doAction method should return its reverse action immediately
    action = action->doAction();
    if (it_ != actions_.end())
        actions_.erase(it_, actions_.end());
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
        //*it_ = (*it_)->createReverseAction();
        //(*it_)->doAction();
        *it_ = (*it_)->doAction();
    }
}

void Director::redo() {
    //auto lastElemIter = actions_.end();
    //--lastElemIter; // to point at the last valid element
    if (it_ != actions_.end()) {
        *it_ = (*it_)->doAction();
        ++it_;
        //*it_ = (*it_)->createReverseAction();
        //(*it_)->doAction();
    }
}


/*if (undoCount_ <= maxCount_ && undoCount_ != 0) {
    actions_
}*/