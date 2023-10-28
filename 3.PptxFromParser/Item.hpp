#ifndef ITEM_HPP
#define ITEM_HPP

#include "definitions.hpp"
#include "Attributes.hpp"

using LTCoordinate2D = std::pair<NumberType, NumberType>;
using RBCoordinate2D = std::pair<NumberType, NumberType>;
using Position = std::pair<LTCoordinate2D, RBCoordinate2D>;

class Item {
    public:
        Type getType();
        Position getPosition();
        void setPosition(Position pos);
        Attributes getAttributes();
        void setAttributes (Attributes attrs);

    private:
        Type type_;
        Position pos_;
        Attributes attrs_;
};

#endif // ITEM_HPP