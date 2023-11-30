#ifndef ELLIPSE_RENDERER_HPP
#define ELLIPSE_RENDERER_HPP

#include "IShapeRenderer.hpp"

class EllipseRenderer : public IShapeRenderer {
    public:    
        EllipseRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // ELLIPSE_RENDERER_HPP