#ifndef CHANGE_SLIDE_ACTION_HPP
#define CHANGE_SLIDE_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Document.hpp"

class ChangeSlideAction : public IAction {
    public:
        ChangeSlideAction(std::shared_ptr<Document> docPtr, std::shared_ptr<Slide> slidePtr, int currentIdx, int newIdx);
    
    public:
        void doAction();
        std::shared_ptr<Slide> getSlidePtr();
        std::shared_ptr<Document> getDocumentPtr();
        int getCurrentIdx();
        int getNewIdx();

    private:    
        std::shared_ptr<Document> docPtr_;
        std::shared_ptr<Slide> slidePtr_; 
        int currentIdx_;
        int newIdx_;
};

#endif // CHANGE_SLIDE_ACTION_HPP