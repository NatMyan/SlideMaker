/*
#ifndef DISPLAY_ITEM_ACTION_HPP
#define DISPLAY_ITEM_ACTION_HPP

#include "Renderer.hpp"
#include "../Data/Item.hpp"

#include <memory>

class DisplayItemAction : public Renderer {
    public:
        DisplayItemAction(Idx idx, std::shared_ptr<Item> item);
        void execute();

    private:
        Idx idx_;
        std::shared_ptr<Item> item_;
};

#endif // DISPLAY_ITEM_ACTION_HPP
*/