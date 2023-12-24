#ifndef I_VISUAL_DISPLAYABLE_HPP
#define I_VISUAL_DISPLAYABLE_HPP

#include "../VariantWrapper.hpp"
#include "../Data/Item.hpp"

#include <memory>
#include <QPainter>

class IVisualDisplayable {
    public:
        virtual ~IVisualDisplayable() = default;
        virtual void draw(QPainter* painter, std::shared_ptr<Item> item) = 0;
};

#endif // I_VISUAL_DISPLAYABLE_HPP
