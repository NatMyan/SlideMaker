#include "RemoveSlideAction.hpp"
#include "AddSlideAction.hpp"

RemoveSlideAction::RemoveSlideAction(std::shared_ptr<Document> doc, int slideIdx) :
    doc_(doc),
    slideIdx_(slideIdx)
{}

std::shared_ptr<IAction>  RemoveSlideAction::doAction() {
    doc_->removeSlide(slideIdx_);
    return std::make_shared<AddSlideAction>(doc_, doc_->getSlide(slideIdx_));
}

/*std::shared_ptr<IAction> RemoveSlideAction::createReverseAction() {
    return std::make_shared<AddSlideAction>(doc_, doc_->getSlide(slideIdx_));
}*/