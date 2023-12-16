#ifndef SHAPE_BASE_HPP
#define SHAPE_BASE_HPP

#include "IShape.hpp"
#include "ITextDisplayable.hpp"
#include "../Data/Item.hpp"
#include "../Data/IItemVisitor.hpp"

#include <ostream>

class ShapeBase : public IShape, public ITextDisplayable { //, public IItemVisitor { //TK: ItemVisitor implements renderer not the shape
    public:
        std::unique_ptr<IShape> clone();
        void display(std::ostream& output, std::shared_ptr<ItemBase> item) final override;
        // void display(VariantWrapper<std::shared_ptr<Item>, std::shared_ptr<ItemGroup> > item, std::ostream& output) final override;

    // private:
        /*template <typename T>
        void display2(T item, std::ostream& output);*/
};

#endif // SHSPE_BASE_HPP