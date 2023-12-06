#ifndef I_VISUAL_DISPLAYABLE_HPP
#define I_VISUAL_DISPLAYABLE_HPP

#include <memory>

class IVisualDisplayable {
    public:
        virtual void draw(QPainter* painter, std::shared_ptr<ItemBase> item) = 0;
};

#endif // I_VISUAL_DISPLAYABLE_HPP
