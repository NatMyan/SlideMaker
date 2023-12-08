#include "AddSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Document> doc, std::shared_ptr<Slide> slide) :
    slide_(slide),
    doc_(doc)
{}

void AddSlideAction::doAction() {
    doc_->addSlide(slide_);
}
