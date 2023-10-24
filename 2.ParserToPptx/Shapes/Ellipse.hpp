#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Shape.hpp"

class Ellipse : public Shape {
    public: 
        Ellipse (ID id, Position pos, std::map<Key, Value> attributes);

    public:
        double getVerticalRadius();
        double getHorizontalRadius();
    // private:
        // double findCoordinateLength(double bigNum, double smallNum);

    private:
        double verticalRadius_;
        double horizontalRadius_;
};

#endif // ELLIPSE_HPP
