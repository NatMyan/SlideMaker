#ifndef ITEM_HPP
#define ITEM_HPP

#include "../Attributes/Attributes.hpp"

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