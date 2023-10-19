#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "definitions.hpp"

#include <map>
#include <tuple>
#include <vector>

class Slide {
    private:
        static std::vector<std::tuple<ID, std::map<std::string, ArgumentType> > > itemStorage_;
        /// TODO: static or not?
};

#endif // SLIDE_HPP