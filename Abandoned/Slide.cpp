#include "Slide.hpp"

std::vector<std::tuple<ID, std::shared_ptr<Shape> > > Slide::getSlide() { 
    return slide_; 
}