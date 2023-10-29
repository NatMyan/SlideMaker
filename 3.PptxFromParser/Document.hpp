#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.hpp"

class Document {
    public:
        using DocumentIterator = DocumentType<std::shared_ptr<Slide> >::iterator;

    public:
        Document();
        Document (int slideNum);

    public:
        DocumentType<std::shared_ptr<Slide> > getSlides();
        void addtoDocument(std::shared_ptr<Slide> slidePtr);
        void removeFromDocument(Idx idx);
        std::shared_ptr<Slide> getSlide(Idx idx);
        DocumentIterator begin();
        DocumentIterator end();

    private:
        DocumentType<std::shared_ptr<Slide> > slides_;
};

#endif // DOCUMENT_HPP