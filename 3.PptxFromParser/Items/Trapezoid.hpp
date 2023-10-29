#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Shape.hpp"

class Trapezoid : public Shape {
    public: 
        Trapezoid (ID id, Position pos, std::map<Key, Value> attributes);

    public:
        double getHeight();
        double getTopWidth();
        double getBottomWidth();
        
    // private:
        // double findCoordinateLength(double bigNum, double smallNum);

    private:
        double bottomWidth_;
        double topWidth_;
        double height_;
};

#endif // TRAPEZOID_HPP
