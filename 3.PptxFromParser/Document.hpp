#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.hpp"

class Document {
    public:
        Document (int slideNum) : slides_(slideNum, Slide{}) {};
        std::vector<Slide> getSlides();

    private:
        std::vector<Slide> slides_;
};

#endif // DOCUMENT_HPP