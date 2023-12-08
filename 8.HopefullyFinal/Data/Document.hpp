#ifndef DOCUMENTT_HPP
#define DOCUMENTT_HPP

#include "Slide.hpp"

class Document {
    public:
        using SlideIterator = std::vector<std::shared_ptr<Slide> >::iterator;

    public:
        Document();
        // Document (int slideNum);

    public:
        int addSlide(std::shared_ptr<Slide> slidePtr);
        void removeSlide(int idx);

        std::shared_ptr<Slide> getSlide(int idx);
        size_t getSlideCount();
        
        SlideIterator begin();
        SlideIterator end();

    private:
        std::vector<std::shared_ptr<Slide> > slides_;
};

#endif // DOCUMENTT_HPP