#ifndef TRAPEZOID_RENDERER_HPP
#define TRAPEZOID_RENDERER_HPP

#include "IShapeRenderer.hpp"

class TrapezoidRenderer : public IShapeRenderer {
    public:    
        TrapezoidRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // TRAPEZOID_RENDERER_HPP