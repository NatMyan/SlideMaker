#ifndef DOCUMENTT_HPP
#define DOCUMENTT_HPP

#include "Slide.hpp"
#include "FormatSize.hpp"

class Document {
    public:
        using SlideIterator = std::vector<std::shared_ptr<Slide> >::iterator;

    public:
        Document();
        // Document (int slideNum);

    public:
        int addSlide(std::shared_ptr<Slide> slidePtr);
        void insertSlide(std::shared_ptr<Slide> slidePtr, int idx);
        void removeSlide(int idx);

        std::shared_ptr<Slide> getSlide(int idx) const;
        std::shared_ptr<Slide> getSlideByItemID(int itemID) const;
        size_t getSlideCount() const;

        std::pair<std::string, std::pair<double, double> > getFormatSize();
        std::pair<double, double> setFormatSize(const std::string& formatName);
        std::string setCustomFormatSize(std::pair<double, double> customSize);

        std::string getOrientation() const;
        void setOrientation(const std::string& orientation);
    
        SlideIterator begin();
        SlideIterator end();

    private:
        std::vector<std::shared_ptr<Slide> > slides_;
        std::pair<std::string, std::pair<double, double> > currFormat_;
        std::string orientation_;
        std::pair<std::string, std::string> orientations_ = {"landscape", "portrait"};
};

#endif // DOCUMENTT_HPP