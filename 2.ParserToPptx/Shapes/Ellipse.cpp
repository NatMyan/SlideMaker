#include "Ellipse.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all is positive, 1st quarter
Ellipse::Ellipse (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Ellipse", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = convertToDouble(attributes, "-t");
        double bottom = convertToDouble(attributes, "-b");
        double right = convertToDouble(attributes, "-r");
        double left = convertToDouble(attributes, "-l");

        verticalRadius_ = (top - bottom) / 2;
        horizontalRadius_ = (right - left) / 2;
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        double width = convertToDouble(attributes, "-w");
        double height = convertToDouble(attributes, "-h");

        verticalRadius_ = height / 2;
        horizontalRadius_ = width / 2;  
    }
}

double Ellipse::getVerticalRadius() {
    return verticalRadius_;
}

double Ellipse::getHorizontalRadius() {
    return horizontalRadius_;
}

///NOTE: let's assume the Slide is only the positive quarter lol
/*double Ellipse::findCoordinateLength (double bigNum, double smallNum) {
    if (bigNum > 0.0) {
        if (smallNum >= 0.0) {
            return bigNum - smallNum;
        }
        else if (smallNum < 0.0) {
            return bigNum + std::abs(smallNum);
        }
    }
    else if (bigNum <= 0.0) {
        // if (smallNum >= 0.0) {
            ///NOTE: this case shouldn't be possible due to the validator
        // }
        if (smallNum < 0.0) {
            return std::abs(bigNum) - std::abs(smallNum);
        }
    }
}*/