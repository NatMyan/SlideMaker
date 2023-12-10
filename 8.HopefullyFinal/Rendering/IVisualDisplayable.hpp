#ifndef I_VISUAL_DISPLAYABLE_HPP
#define I_VISUAL_DISPLAYABLE_HPP

#include "../VariantWrapper.hpp"
#include "../Data/Item.hpp"
#include "../Data/ItemGroup.hpp"

#include <memory>
#include <QPainter>
#include <ostream>

class IVisualDisplayable {
    public:
        virtual void draw(std::shared_ptr<ItemBase> item, QPainter* painter) = 0;
};

#endif // I_VISUAL_DISPLAYABLE_HPP
