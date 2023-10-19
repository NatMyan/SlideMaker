#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.hpp"

#include <vector>

class Document {
    public:
        Document(int slideNum);

    private:
        static std::vector<Slide> slides_;
};

#endif // DOCUMENT_HPP