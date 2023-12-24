#ifndef MOVE_SLIDE_ACTION_HPP
#define MOVE_SLIDE_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Document.hpp"

class MoveSlideAction : public IAction {
    public:
        MoveSlideAction(std::shared_ptr<Document> docPtr, std::shared_ptr<Slide> slidePtr, int currentIdx, int newIdx);
    
    public:
        std::shared_ptr<IAction> doAction();
        // std::shared_ptr<IAction> createReverseAction();

    private:    
        std::shared_ptr<Document> docPtr_;
        std::shared_ptr<Slide> slidePtr_; 
        int currentIdx_;
        int newIdx_;
};

#endif // MOVE_SLIDE_ACTION_HPP