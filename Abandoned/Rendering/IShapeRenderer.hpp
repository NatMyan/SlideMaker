#ifndef I_SHAPE_HPP
#define I_SHAPE_HPP

#include "../Data/Item.hpp"

#include <ostream>
#include <QPainter>

class IShapeRenderer {
    public:
        IShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr);
        virtual ~IShapeRenderer() = default;
        virtual void draw(QPainter* painter) = 0;
        void print(std::ostream& stream);

    protected:
        Qt::GlobalColor stringToGlobalColor(const QString& colorName);
    
    private:
        std::shared_ptr<Item> itemPtr_;
        Idx idx_;
};

#endif // I_SHAPE_HPP