#include "Ellipse.hpp"

///TODO: if t,b,r,l are pos and neg - ? -> assuming all is positive, 1st quarter
Ellipse::Ellipse (ID id, Position pos, Attributes attributes) : Item ("Ellipse", id, pos, attributes) {
    if (attributes.getValue("-t") != Value() && attributes.getValue("-l") != Value() &&  
        attributes.getValue("-b") != Value() && attributes.getValue("-r") != Value()) {

        double top = defs::convertToDouble(attributes.getValue("-t"));
        double bottom = defs::convertToDouble(attributes.getValue("-b"));
        double right = defs::convertToDouble(attributes.getValue("-r"));
        double left = defs::convertToDouble(attributes.getValue("-l"));

        verticalRadius_ = (bottom - top) / 2;
        horizontalRadius_ = (right - left) / 2;
    }
    else if (attributes.getValue("-w") != Value() && attributes.getValue("-h") != Value()
        && attributes.getValue("-x") != Value() && attributes.getValue("-y") != Value()) {

        double width = defs::convertToDouble(attributes.getValue("-w"));
        double height = defs::convertToDouble(attributes.getValue("-h"));

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