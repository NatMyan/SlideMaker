#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "definitions.hpp"

#include <map>
#include <tuple>
#include <vector>

class Slide {
    private:
        std::vector<std::tuple<ID, std::map<std::string, ArgumentType> > > itemStorage_;
        /// TODO: static or not?
        /// TODO: ID belongs to Shape, not command...
};

#endif // SLIDE_HPP