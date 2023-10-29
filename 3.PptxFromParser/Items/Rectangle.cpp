#include "Rectangle.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all is positive, 1st quarter
Rectangle::Rectangle (ID id, Position pos, Attributes attributes) : Item ("Rectangle", id, pos, attributes) {
    if (attributes.getValue("-t") != Value() && attributes.getValue("-l") != Value() &&  
        attributes.getValue("-b") != Value() && attributes.getValue("-r") != Value()) {

        double top = defs::convertToDouble(attributes.getValue("-t"));
        double bottom = defs::convertToDouble(attributes.getValue("-b"));
        double right = defs::convertToDouble(attributes.getValue("-r"));
        double left = defs::convertToDouble(attributes.getValue("-l"));

        width_ = (top - bottom);
        height_ = (right - left);
    }
    else if (attributes.getValue("-w") != Value() && attributes.getValue("-h") != Value()
        && attributes.getValue("-pos") != Value()) {

        width_ = defs::convertToDouble(attributes.getValue("-w"));
        height_ = defs::convertToDouble(attributes.getValue("-h"));  
    }
}

double Rectangle::getWidth() {
    return width_;
}

double Rectangle::getHeight() {
    return height_;
}