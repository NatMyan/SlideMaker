#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP

#include "IShapeRenderer.hpp"

class ShapeFactory {
    public:
        std::shared_ptr<IShapeRenderer> createShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
};

#endif // SHAPE_FACTORY_HPP