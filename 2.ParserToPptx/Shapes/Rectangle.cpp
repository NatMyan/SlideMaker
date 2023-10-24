#include "Rectangle.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all is positive, 1st quarter
Rectangle::Rectangle (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Rectangle", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = convertToDouble(attributes, "-t");
        double bottom = convertToDouble(attributes, "-b");
        double right = convertToDouble(attributes, "-r");
        double left = convertToDouble(attributes, "-l");

        width_ = (top - bottom);
        height_ = (right - left);
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        width_ = convertToDouble(attributes, "-w");
        height_ = convertToDouble(attributes, "-h");  
    }
}

double Rectangle::getWidth() {
    return width_;
}

double Rectangle::getHeight() {
    return height_;
}