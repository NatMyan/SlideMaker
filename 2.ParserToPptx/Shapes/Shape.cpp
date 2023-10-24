#include "Shape.hpp"

///TODO: add default attributes
Shape::Shape(Type type, ID id, Position pos,  std::map<Key, Value> attributes) :
    type_(type), id_(id), pos_(pos), attributes_(attributes)
{} 

void Shape::setPosition(Position pos) {
    pos_ = pos;
}

Position Shape::getPosition() const {
    return pos_;
}

ID Shape::getID() const {
    return id_;
}

Type Shape::getType() const {
    return type_;
}

Value Shape::getAttribute(Key key) { // can't be const, why?
    if (attributes_.find(key) != attributes_.end())
        return attributes_[key];
    return "val_not_found";
}

void Shape::setAttribute(Key key, Value val) {
    attributes_[key] = val;
}

double Shape::convertToDouble(std::map<Key, Value>& attributes, const Key& key) {
    if (attributes.find(key) != attributes.end()) {
        if (std::holds_alternative<double>(attributes[key])) {
            return std::get<double>(attributes[key]);
        } 
        else if (std::holds_alternative<int>(attributes[key])) {
            return static_cast<double>(std::get<int>(attributes[key]));
        }
    }
    ///TODO: is else if needed, if the validator already validates everything, or throw exception
}