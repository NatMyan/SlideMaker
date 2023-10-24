#include "Shape.hpp"

Shape::Shape(Position pos, ID id, Type type, std::map<Key, Value> attributes) :
    pos_(pos), id_(id), type_(type), attributes_(attributes)
{} 