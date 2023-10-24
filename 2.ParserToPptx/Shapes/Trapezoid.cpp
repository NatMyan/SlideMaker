#include "Trapezoid.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all are positive, 1st quarter
Trapezoid::Trapezoid (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Trapezoid", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = convertToDouble(attributes, "-t");
        double bottom = convertToDouble(attributes, "-b");
        double right = convertToDouble(attributes, "-r");
        double left = convertToDouble(attributes, "-l");

        bottomWidth_ = (top - bottom);
        topWidth_ = (top - bottom) / 2;
        height_ = (right - left);
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        bottomWidth_ = convertToDouble(attributes, "-w");
        topWidth_ = convertToDouble(attributes, "-w") / 2;
        height_ = convertToDouble(attributes, "-h");  
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