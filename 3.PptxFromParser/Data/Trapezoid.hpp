#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Item.hpp"

class Trapezoid : public Item {
    public: 
        Trapezoid (ID id, Position pos, Attributes attributes);

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
