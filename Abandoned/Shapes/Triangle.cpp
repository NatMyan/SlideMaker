#include "Triangle.hpp"

Triangle::Triangle (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Trapezoid", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = defs::convertToDouble(attributes, "-t");
        double bottom = defs::convertToDouble(attributes, "-b");
        double right = defs::convertToDouble(attributes, "-r");
        double left = defs::convertToDouble(attributes, "-l");

        base_ = (top - bottom);
        height_ = (right - left);
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        base_ = defs::convertToDouble(attributes, "-w");
        height_ = defs::convertToDouble(attributes, "-h");  
    }
}

double Triangle::getHeight() {
    return height_;
}

double Triangle::getBase() {
    return base_;
}