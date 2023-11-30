#ifndef TRIANGLE_RENDERER_HPP
#define TRIANGLE_RENDERER_HPP

#include "IShapeRenderer.hpp"

class TriangleRenderer : public IShapeRenderer {
    public:    
        TriangleRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // TRIANGLE_RENDERER_HPP