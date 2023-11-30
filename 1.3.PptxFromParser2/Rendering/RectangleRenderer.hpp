#ifndef RECTANGLE_RENDERER_HPP
#define RECTANGLE_RENDERER_HPP

#include "IShapeRenderer.hpp"

class RectangleRenderer : public IShapeRenderer {
    public:    
        RectangleRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        void draw(QPainter* painter);

    private:
        QString getColour(Value colour);
        Qt::GlobalColor stringToGlobalColor(const QString& colorName);

    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // RECTANGLE_RENDERER_HPP