#ifndef ACTION_CONTAINER_HPP
#define ACTION_CONTAINER_HPP

#include "IAction.hpp"

#include <list>

///NOTE: to replace stack and an iterator on it, to simplify testing and coding (in my opinion and understanding)
class ActionContainer { 
    public:
        void addRedoableAction(std::shared_ptr<IAction> action);
        void addUndoableAction(std::shared_ptr<IAction> action);

        void popFrontRedoable();
        void popBackRedoable();

        void popFrontUndoable();
        void popBackRedoable();

    private:
        std::list<std::shared_ptr<IAction> > undoables_;
        std::list<std::shared_ptr<IAction> > redoables_;
};

#endif // ACTION_CONTAINER_HPP