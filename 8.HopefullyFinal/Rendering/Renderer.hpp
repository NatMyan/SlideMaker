#ifndef RENDERERR_HPP
#define RENDERERR_HPP

#include "../Data/ItemBase.hpp"

class Renderer {
    public:
        void draw();
        void display(std::shared_ptr<ItemBase> item);
        // void display(std::shared_ptr<Item> slide);
};

#endif // RENDERERR_HPP