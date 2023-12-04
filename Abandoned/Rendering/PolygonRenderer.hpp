#ifndef POLYGON_RENDERER_HPP
#define POLYGON_RENDERER_HPP

#include "IShapeRenderer.hpp"

class PolygonRenderer : public IShapeRenderer {
    public:    
        PolygonRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // POLYGON_RENDERER_HPP