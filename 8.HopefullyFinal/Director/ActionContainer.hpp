#ifndef ACTION_CONTAINER_HPP
#define ACTION_CONTAINER_HPP

#include "IAction.hpp"

#include <list>

class ActionContainer {
    public:
        void addAction(std::shared_ptr<IAction> action);
        void popFrontAction();
        void popBackAction();

    private:
        std::list<std::shared_ptr<IAction> > undoables_;
        std::list<std::shared_ptr<IAction> > redoables_;
};

#endif // ACTION_CONTAINER_HPP