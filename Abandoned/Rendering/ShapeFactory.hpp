#ifndef SHAPEE_FACTORY_HPP
#define SHAPEE_FACTORY_HPP

#include "IShapeRenderer.hpp"

class ShapeFactory {
    public:
        std::shared_ptr<IShapeRenderer> createShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
};

#endif // SHAPEE_FACTORY_HPP