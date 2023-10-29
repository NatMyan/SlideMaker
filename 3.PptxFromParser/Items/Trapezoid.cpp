#include "Trapezoid.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all are positive, 1st quarter
Trapezoid::Trapezoid (ID id, Position pos, Attributes attributes) : Item ("Trapezoid", id, pos, attributes) {
    if (attributes.getValue("-t") != Value() && attributes.getValue("-l") != Value() &&  
        attributes.getValue("-b") != Value() && attributes.getValue("-r") != Value()) {

        double top = defs::convertToDouble(attributes.getValue("-t"));
        double bottom = defs::convertToDouble(attributes.getValue("-b"));
        double right = defs::convertToDouble(attributes.getValue("-r"));
        double left = defs::convertToDouble(attributes.getValue("-l"));

        bottomWidth_ = (top - bottom);
        topWidth_ = (top - bottom) / 2;
        height_ = (right - left);
    }
    else if (attributes.getValue("-w") != Value() && attributes.getValue("-h") != Value()
        && attributes.getValue("-pos") != Value()) {

        bottomWidth_ = defs::convertToDouble(attributes.getValue("-w"));
        topWidth_ = defs::convertToDouble(attributes.getValue("-w")) / 2;
        height_ = defs::convertToDouble(attributes.getValue("-h"));  
    }
}

double Trapezoid::getHeight() {
    return height_;
}

double Trapezoid::getTopWidth() {
    return topWidth_;
}

double Trapezoid::getBottomWidth() {
    return bottomWidth_;
}