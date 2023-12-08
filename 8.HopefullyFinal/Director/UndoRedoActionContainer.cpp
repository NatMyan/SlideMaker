#include "UndoRedoActionContainer.hpp"

void UndoRedoActionContainer::addAction(std::shared_ptr<IAction> action) {
    actions_.push_back(action);
    if (actions_.size() > maxAmount_) 
        actions_.pop_front();
}

void UndoRedoActionContainer::popFrontRedoable() {
    redoables_.pop_front();
}

void UndoRedoActionContainer::popBackRedoable() {
    redoables_.pop_back();
}

void UndoRedoActionContainer::popFrontUndoable() {
    undoables_.pop_front();
}

void UndoRedoActionContainer::popBackRedoable() {
    undoables_.pop_back();
}

void UndoRedoActionContainer::addRedoableAction(std::shared_ptr<IAction> action) {
    redoables_.push_back(action);
}

void UndoRedoActionContainer::addUndoableAction(std::shared_ptr<IAction> action) {
    undoables_.push_back(action);
}