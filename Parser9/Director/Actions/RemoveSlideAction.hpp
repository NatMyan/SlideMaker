#ifndef REMOVE_SLIDE_ACTION_HPP
#define REMOVE_SLIDE_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Document.hpp"

namespace dir {

class RemoveSlideAction : public IAction {
    public:
        RemoveSlideAction(std::shared_ptr<Document> doc, int slideIdx);
    
    public:
        std::shared_ptr<IAction> doAction();
        // std::shared_ptr<IAction> createReverseAction();
    
    private:
        std::shared_ptr<Document> doc_;
        int slideIdx_;
};

}

#endif // REMOVE_SLIDE_ACTION_HPP