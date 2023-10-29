#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "../definitions.hpp"

using LTCoordinate2D = std::pair<NumberType, NumberType>;
using RBCoordinate2D = std::pair<NumberType, NumberType>;
using Position = std::pair<LTCoordinate2D, RBCoordinate2D>;

class Shape {
    public:
        Shape (Type type, ID id, Position pos, std::map<Key, Value> attributes);

    public:
        void setPosition(Position pos);
        Position getPosition() const;
        ID getID() const;
        Type getType() const;
        Value getAttribute(Key key);
        void setAttribute(Key key, Value val);
    
    // protected:
        // double convertToDouble(std::map<Key, Value>& attributes, const Key& key);

    protected:
        Position pos_;
        ID id_;
        Type type_;
        std::map<Key, Value> attributes_;
};

#endif // SHAPE_HPP