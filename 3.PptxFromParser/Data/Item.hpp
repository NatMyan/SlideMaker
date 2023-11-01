#ifndef ITEM_HPP
#define ITEM_HPP

#include "../definitions.hpp"
#include "Attributes.hpp"

using LTCoordinate2D = std::pair<NumberType, NumberType>;
using RBCoordinate2D = std::pair<NumberType, NumberType>;
using Position = std::pair<LTCoordinate2D, RBCoordinate2D>;

class Item {
    public:
        Item (Type type, ID id, Position pos, Attributes attributes);

    public:
        ID getID() const;

        Type getType() const;
        void setType(Type type);

        Position getPosition() const;
        void setPosition(Position pos);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);
        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);

    private:
        ID id_;
        Type type_;
        Position pos_;
        Attributes attrs_;
};

#endif // ITEM_HPP