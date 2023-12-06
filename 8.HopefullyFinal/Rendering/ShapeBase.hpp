#ifndef SHAPE_BASE_HPP
#define SHAPE_BASE_HPP

#include "IShape.hpp"
#include "ITextDisplayable.hpp"

class ShapeBase : public IShape, public ITextDisplayable {
    public:
        std::unique_ptr<IShape> clone();
        void display(std::shared_ptr<ItemBase> item, std::ostream& output);
};

#endif // SHSPE_BASE_HPP