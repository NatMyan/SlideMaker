#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Item.hpp"

class Ellipse : public Item {
    public: 
        Ellipse (ID id, Position pos, Attributes attributes);

    public:
        double getVerticalRadius();
        double getHorizontalRadius();

    private:
        double verticalRadius_;
        double horizontalRadius_;
};

#endif // ELLIPSE_HPP
