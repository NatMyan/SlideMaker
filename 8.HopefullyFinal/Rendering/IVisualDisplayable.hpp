#ifndef I_VISUAL_DISPLAYABLE_HPP
#define I_VISUAL_DISPLAYABLE_HPP

#include "../VariantWrapper.hpp"
#include "../Data/Item.hpp"
#include "../Data/ItemGroup.hpp"

#include <memory>
#include <QPainter>

class IVisualDisplayable {
    public:
        virtual void draw(VariantWrapper<std::shared_ptr<Item>, std::shared_ptr<ItemGroup> > item, QPainter* painter) = 0;
};

#endif // I_VISUAL_DISPLAYABLE_HPP
