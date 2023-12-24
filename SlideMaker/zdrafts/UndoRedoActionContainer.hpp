#ifndef UNDO_REDO_ACTION_CONTAINER_HPP
#define UNDO_REDO_ACTION_CONTAINER_HPP

#include "IAction.hpp"

#include <list>

///NOTE: to replace stack and an iterator on it, to simplify testing and coding (in my opinion and understanding)
class UndoRedoActionContainer { 
    public:
        void addAction(std::shared_ptr<IAction> action);

        void popFrontRedoable();
        void popBackRedoable();

        void popFrontUndoable();
        void popBackRedoable();
    
    private:
        void addRedoableAction(std::shared_ptr<IAction> action);
        void addUndoableAction(std::shared_ptr<IAction> action);

    private:
        std::list<std::shared_ptr<IAction> > actions_;
        std::list<std::shared_ptr<IAction> > undoneActions_;
        int maxAmount_ = 5;
};

#endif // UNDO_REDO_ACTION_CONTAINER_HPP

