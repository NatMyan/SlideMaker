#ifndef DIRECTORR_HPP
#define DIRECTORR_HPP

#include "Actions/IAction.hpp"
#include "Actions/AddItemAction.hpp"
#include "Actions/AddSlideAction.hpp"
#include "Actions/RemoveItemAction.hpp"
#include "Actions/RemoveSlideAction.hpp"
#include "Actions/ChangeItemAction.hpp"
#include "Actions/MoveSlideAction.hpp"

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
        std::list<std::shared_ptr<IAction> >::iterator currPosIter_;
        // int undoCount_;
        // int redoCount_;
};

#endif // DIRECTOR_HPP