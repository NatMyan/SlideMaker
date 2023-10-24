#include "Line.hpp"

#include <cmath>

Line::Line (ID id, Position pos, std::map<Key, Value> attributes) : Shape ("Line", id, pos, attributes) {
    if (attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end() &&  
        attributes.find("-t") != attributes.end() && attributes.find("-t") != attributes.end()) {

        double top = convertToDouble(attributes, "-t");
        double bottom = convertToDouble(attributes, "-b");
        double right = convertToDouble(attributes, "-r");
        double left = convertToDouble(attributes, "-l");

        length_ = sqrt(pow(top - bottom, 2) + pow (right - left, 2));
    }
    else if (attributes.find("-w") != attributes.end() && attributes.find("-h") != attributes.end()
        && attributes.find("-pos") != attributes.end()) {

        double width = convertToDouble(attributes, "-w");
        double height = convertToDouble(attributes, "-h");

        length_ = sqrt(pow(width,2) + pow(height, 2));
    }    
}
