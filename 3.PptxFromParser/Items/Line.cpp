#include "Line.hpp"

#include <cmath>

Line::Line (ID id, Position pos, Attributes attributes) : Item ("Line", id, pos, attributes) {
    if (attributes.getValue("-t") != Value() && attributes.getValue("-l") != Value() &&  
        attributes.getValue("-b") != Value() && attributes.getValue("-r") != Value()) {

        double top = defs::convertToDouble(attributes.getValue("-t"));
        double bottom = defs::convertToDouble(attributes.getValue("-b"));
        double right = defs::convertToDouble(attributes.getValue("-r"));
        double left = defs::convertToDouble(attributes.getValue("-l"));

        length_ = sqrt(pow(top - bottom, 2) + pow (right - left, 2));
    }
    else if (attributes.getValue("-w") != Value() && attributes.getValue("-h") != Value()
        && attributes.getValue("-pos") != Value()) {

        double width = defs::convertToDouble(attributes.getValue("-w"));
        double height = defs::convertToDouble(attributes.getValue("-h"));

        length_ = sqrt(pow(width,2) + pow(height, 2));
    }    
}
