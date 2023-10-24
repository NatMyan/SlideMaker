#include "Rectangle.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all is positive, 1st quarter
Rectangle::Rectangle (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Rectangle", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = defs::convertToDouble(attributes, "-t");
        double bottom = defs::convertToDouble(attributes, "-b");
        double right = defs::convertToDouble(attributes, "-r");
        double left = defs::convertToDouble(attributes, "-l");

        width_ = (top - bottom);
        height_ = (right - left);
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        width_ = defs::convertToDouble(attributes, "-w");
        height_ = defs::convertToDouble(attributes, "-h");  
    }
}

double Rectangle::getWidth() {
    return width_;
}

double Rectangle::getHeight() {
    return height_;
}