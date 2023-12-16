#include "AddSlideAction.hpp"
#include "RemoveSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Document> doc, std::shared_ptr<Slide> slide) :
    slide_(slide),
    doc_(doc)
{}

void AddSlideAction::doAction() {
    doc_->addSlide(slide_); //TK: you also need to keep the original posiotion to redo correctly
}

std::shared_ptr<IAction> AddSlideAction::createReverseAction() {
    return std::make_shared<RemoveSlideAction>(doc_, doc_->getSlideCount() - 1);
}