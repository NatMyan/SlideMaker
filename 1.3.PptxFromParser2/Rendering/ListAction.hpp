#ifndef LIST_ITEM_ACTION_HPP
#define LIST_ITEM_ACTION_HPP

#include "Renderer.hpp"
#include "../definitions.hpp"

#include <memory>

class ListAction : public Renderer {
    public:
        ListAction(Idx idx, Type type, ID id);
        void execute();

    private:
        Idx idx_;
        Type type_;
        ID id_;
};

#endif // LIST_ITEM_ACTION_HPP