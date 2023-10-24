#include "Triangle.hpp"

Triangle::Triangle (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Trapezoid", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = convertToDouble(attributes, "-t");
        double bottom = convertToDouble(attributes, "-b");
        double right = convertToDouble(attributes, "-r");
        double left = convertToDouble(attributes, "-l");

        base_ = (top - bottom);
        height_ = (right - left);
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        base_ = convertToDouble(attributes, "-w");
        height_ = convertToDouble(attributes, "-h");  
    }
}

double Triangle::getHeight() {
    return height_;
}

double Triangle::getBase() {
    return base_;
}