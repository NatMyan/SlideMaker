#ifndef DIRECTORR_HPP
#define DIRECTORR_HPP

#include "IAction.hpp"
#include "AddItemAction.hpp"
#include "AddSlideAction.hpp"
#include "RemoveItemAction.hpp"
#include "RemoveSlideAction.hpp"
#include "ChangeItemAction.hpp"
#include "ChangeSlideAction.hpp"

#include <list>

class Director {
    public:
        Director();

    public:
        void runAction(std::shared_ptr<IAction> action);
        void undo();
        void redo();
    
    private:
        const int maxCount_ = 6;
        std::list<std::shared_ptr<IAction> > actions_;
        std::list<std::shared_ptr<IAction> >::iterator it_; //TK: Call your variables appropriately, i.e itCurrentPos_
        // int undoCount_;
        // int redoCount_;
};

#endif // DIRECTOR_HPP