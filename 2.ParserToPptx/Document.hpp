#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.hpp"

#include <vector>

/* 
    I understand Document as a container only, in a sense that it contains slides
    but since commands can be added and/or removed, I'll separate them from Document into DocumentCommandExecutors
*/

class Document { 
    public:
        Document (int slideNum) : slides_(slideNum) {};

    protected:
        std::vector<Slide> slides_;
};

#endif // DOCUMENT_HPP