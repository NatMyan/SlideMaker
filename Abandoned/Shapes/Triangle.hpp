#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
    public: 
        Triangle (ID id, Position pos, std::map<Key, Value> attributes);

    public:
        double getHeight();
        double getBase();

    private:
        double base_;
        double height_;
};


#endif // TRIANGLE_HPP