#include "AddSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Document> doc, std::shared_ptr<Slide> slide) :
    slide_(slide),
    doc_(doc)
{}

void AddSlideAction::doAction() {
    doc_->addSlide(slide_);
}

std::shared_ptr<Slide> AddSlideAction::getSlidePtr() {
    return slide_;
}

std::shared_ptr<Document> AddSlideAction::getDocumentPtr() {
    return doc_;
}