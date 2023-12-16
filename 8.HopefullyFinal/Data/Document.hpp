#ifndef DOCUMENTT_HPP
#define DOCUMENTT_HPP

#include "Slide.hpp"
#include "FormatSize.hpp"

//TK: Since you are fun of templates  you can use template class for the poor Container functionality
//TK: Same container could be used as base for the Document and  ItemGroup classes
// And you will avoid code duplication, instead will increase your code reusability
template <class T>
class Container {

        int add(std::shared_ptr<T> slidePtr);
        void insert(std::shared_ptr<T> slidePtr, size_t idx);
        void remove(size_t idx);

        std::shared_ptr<Slide> getAt(size_t idx) const;
        size_t getCount() const;

        Iterator begin();
        Iterator end();

    private:
        std::vector<std::shared_ptr<T> > children_;
}

class Document : public Container<Slide>  {
    public:
        using SlideIterator = std::vector<std::shared_ptr<Slide> >::iterator;

    public:
        Document();
        // Document (int slideNum);

    public:
        //int addSlide(std::shared_ptr<Slide> slidePtr);
        //void insertSlide(std::shared_ptr<Slide> slidePtr, int idx);
        //void removeSlide(int idx);

        //std::shared_ptr<Slide> getSlide(int idx) const;
        //size_t getSlideCount() const;

        std::pair<std::string, std::pair<double, double> > getFormatSize();
        std::pair<double, double> setFormatSize(const std::string& formatName);
        std::string setCustomFormatSize(std::pair<double, double> customSize);

        std::string getOrientation() const;
        void setOrientation(const std::string& orientation);
    
        //SlideIterator begin();
        //SlideIterator end();

    private:
        //std::vector<std::shared_ptr<Slide> > slides_;
        std::pair<std::string, std::pair<double, double> > currFormat_;
        std::string orientation_;
        std::pair<std::string, std::string> orientations_ = {"landscape", "portrait"};
};

#endif // DOCUMENTT_HPP