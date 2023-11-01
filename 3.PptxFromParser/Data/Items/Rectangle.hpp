#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Item.hpp"

class Rectangle : public Item {
    public: 
        Rectangle (ID id, Position pos, Attributes attributes);

    public:
        double getHeight();
        double getWidth();
        
    // private:
        // double findCoordinateLength(double bigNum, double smallNum);

    private:
        double width_;
        double height_;
};

#endif // RECTANGLE_HPP