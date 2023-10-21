#include "Shape.hpp"

Shape::Shape(Position pos, ID id, Type type, std::map<Key, Value> attribute) :
    pos_(pos), id_(id), type_(type), attribute_(attribute)
{} 