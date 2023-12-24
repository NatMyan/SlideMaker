#ifndef ADD_SLIDE_ACTION_HPP
#define ADD_SLIDE_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Document.hpp"

class AddSlideAction : public IAction {
    public:
        AddSlideAction(std::shared_ptr<Document> doc, std::shared_ptr<Slide> slide);
    
    public:
        std::shared_ptr<IAction> doAction();
        // std::shared_ptr<IAction> createReverseAction();

    private:
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Slide> slide_;
};

#endif // ADD_SLIDE_ACTION_HPP