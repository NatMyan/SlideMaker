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
        std::list<std::shared_ptr<IAction> > undoables_;
        std::list<std::shared_ptr<IAction> > redoables_;
};

#endif // UNDO_REDO_ACTION_CONTAINER_HPP

/*

class UndoRedoContainer {
private:
    std::stack<BaseAction*> actions;
    std::stack<BaseAction*> undoneActions;
    int undoCount;
    int redoCount;

public:
    UndoRedoContainer() : undoCount(0), redoCount(0) {}

    ~UndoRedoContainer() {
        clearStack(actions);
        clearStack(undoneActions);
    }

    void addAction(BaseAction* action) {
        if (redoCount > 0) {
            clearStack(undoneActions);
            redoCount = 0;
        }

        action->execute();
        actions.push(action);
        undoCount++;
    }

    void undoAction() {
        if (undoCount > 0 && !actions.empty()) {
            BaseAction* undoneAction = actions.top();
            undoneAction->undo();
            actions.pop();
            undoneActions.push(undoneAction);
            undoCount--;
        }
    }

    void redoAction() {
        if (redoCount > 0 && !undoneActions.empty()) {
            BaseAction* redoneAction = undoneActions.top();
            redoneAction->execute();
            undoneActions.pop();
            actions.push(redoneAction);
            redoCount--;
        }
    }

private:
    void clearStack(std::stack<BaseAction*>& actionStack) {
        while (!actionStack.empty()) {
            delete actionStack.top();
            actionStack.pop();
        }
    }
};

int main() {
    UndoRedoContainer container;

    container.addAction(new AddItemAction());
    container.addAction(new RemoveItemAction());

    container.undoAction();
    container.redoAction(); // This should not execute because undoCount is 0

    return 0;
}

*/