#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "../definitions.hpp"

using LTCoordinate2D = std::pair<ArgumentType, ArgumentType>;
using RBCoordinate2D = std::pair<ArgumentType, ArgumentType>;
using Position = std::pair<LTCoordinate2D, RBCoordinate2D>;
using ID = int;
using Type = std::string;
using Key = std::string;
using Value = ArgumentType;

class Shape {
    public:
        Shape(Position pos, ID id, Type type, std::map<Key, Value> attribute);

    public:
        void setPosition(Position pos);
        Position getPosition();
        ID getID();
        Type getType();
        Value getAttribute(Key);
        bool setAttribute(Key, Value);
        
    private:
        Position pos_;
        ID id_;
        Type type_;
        std::map<Key, Value> attribute_;
};

#endif // SHAPE_HPP