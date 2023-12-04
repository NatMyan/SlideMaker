#ifndef LINE_RENDERER_HPP
#define LINE_RENDERER_HPP

#include "IShapeRenderer.hpp"

class LineRenderer : public IShapeRenderer {
    public:    
        LineRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // LINE_RENDERER_HPP