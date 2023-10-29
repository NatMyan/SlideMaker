#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
    public: 
        Rectangle (ID id, Position pos, std::map<Key, Value> attributes);

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