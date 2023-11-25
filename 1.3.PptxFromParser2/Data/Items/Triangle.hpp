#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Item.hpp"

class Triangle : public Item {
    public: 
        Triangle (ID id, Position pos, Attributes attributes);

    public:
        double getHeight();
        double getBase();

    private:
        double base_;
        double height_;
};


#endif // TRIANGLE_HPP