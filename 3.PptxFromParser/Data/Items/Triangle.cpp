#include "Triangle.hpp"

Triangle::Triangle (ID id, Position pos, Attributes attributes) : Item ("Triangle", id, pos, attributes) {
    if (attributes.getValue("-t") != Value() && attributes.getValue("-l") != Value() &&  
        attributes.getValue("-b") != Value() && attributes.getValue("-r") != Value()) {

        double top = defs::convertToDouble(attributes.getValue("-t"));
        double bottom = defs::convertToDouble(attributes.getValue("-b"));
        double right = defs::convertToDouble(attributes.getValue("-r"));
        double left = defs::convertToDouble(attributes.getValue("-l"));

        base_ = (bottom - top);
        height_ = (right - left);
    }
    else if (attributes.getValue("-w") != Value() && attributes.getValue("-h") != Value()
        && attributes.getValue("-x") != Value() && attributes.getValue("-y") != Value()) {

        base_ = defs::convertToDouble(attributes.getValue("-w"));
        height_ = defs::convertToDouble(attributes.getValue("-h"));  
    }
}

double Triangle::getHeight() {
    return height_;
}

double Triangle::getBase() {
    return base_;
}