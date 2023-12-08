#ifndef DIRECTORR_HPP
#define DIRECTORR_HPP

#include "IAction.hpp"
#include "ActionContainer.hpp"
#include "AddItemAction.hpp"
#include "AddSlideAction.hpp"
#include "RemoveItemAction.hpp"
#include "RemoveSlideAction.hpp"
#include "ChangeItemAction.hpp"
#include "ChangeSlideAction.hpp"

class Director {
    public:
        Director();

    public:
        void runAction(std::shared_ptr<IAction> action);
        void undo();
        void redo();
    
    private:
        std::list<std::shared_ptr<IAction> > undoables_;
        std::list<std::shared_ptr<IAction> > redoables_;
};

#endif // DIRECTOR_HPP