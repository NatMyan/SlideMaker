#include "ActionContainer.hpp"

void ActionContainer::addAction(std::shared_ptr<IAction> action) {
    
}

void ActionContainer::popFrontRedoable() {
    redoables_.pop_front();
}

void ActionContainer::popBackRedoable() {
    redoables_.pop_back();
}

void ActionContainer::popFrontUndoable() {
    undoables_.pop_front();
}

void ActionContainer::popBackRedoable() {
    undoables_.pop_back();
}

void ActionContainer::addRedoableAction(std::shared_ptr<IAction> action) {
    redoables_.push_back(action);
}

void ActionContainer::addUndoableAction(std::shared_ptr<IAction> action) {
    undoables_.push_back(action);
}