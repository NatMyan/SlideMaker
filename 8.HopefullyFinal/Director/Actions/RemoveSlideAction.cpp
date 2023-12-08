#include "RemoveSlideAction.hpp"

RemoveSlideAction::RemoveSlideAction(std::shared_ptr<Document> doc, int slideIdx) :
    doc_(doc),
    slideIdx_(slideIdx)
{}

void RemoveSlideAction::doAction() {
    doc_->removeSlide(slideIdx_);
}
