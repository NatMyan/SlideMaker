#include "MoveSlideAction.hpp"

MoveSlideAction::MoveSlideAction(std::shared_ptr<Document> docPtr, std::shared_ptr<Slide> slidePtr, int currentIdx, int newIdx) :
    docPtr_(docPtr),
    slidePtr_(slidePtr),
    currentIdx_(currentIdx),
    newIdx_(newIdx)
{}

std::shared_ptr<IAction> MoveSlideAction::doAction() {
    docPtr_->removeSlide(currentIdx_);
    docPtr_->insertSlide(slidePtr_, newIdx_);
    return std::make_shared<MoveSlideAction>(docPtr_, slidePtr_, newIdx_, currentIdx_);
}

/*std::shared_ptr<IAction> MoveSlideAction::createReverseAction() {
    return std::make_shared<MoveSlideAction>(docPtr_, slidePtr_, newIdx_, currentIdx_);
}*/