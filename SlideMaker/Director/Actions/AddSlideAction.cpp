#include "AddSlideAction.hpp"
#include "RemoveSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Document> doc, std::shared_ptr<Slide> slide) :
    slide_(slide),
    doc_(doc)
{}

std::shared_ptr<IAction> AddSlideAction::doAction() {
    doc_->addSlide(slide_);
    return std::make_shared<RemoveSlideAction>(doc_, doc_->getSlideCount() - 1);
}

/*std::shared_ptr<IAction> AddSlideAction::createReverseAction() {
    return std::make_shared<RemoveSlideAction>(doc_, doc_->getSlideCount() - 1);
}*/