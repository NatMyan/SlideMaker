#ifndef RENDERERR_HPP
#define RENDERERR_HPP

#include "../Data/Item.hpp"
#include "../Data/ItemGroup.hpp"
#include "../Data/IItemVisitor.hpp"
#include "../Data/Slide.hpp"
#include "ShapeLibrary.hpp"

#include <memory>
#include <QImage>

namespace ren {

using IItemVisitor = dat::IItemVisitor;
using ItemGroup = dat::ItemGroup;
using Slide = dat::Slide;

class Renderer : public IItemVisitor {
    struct InvalidShapeException : public Exception { using Exception::Exception; };
    struct InvalidPointerException : public Exception { using Exception::Exception; };
    struct OutputStreamFailException : public Exception { using Exception::Exception; };

    public:
        Renderer();
        void draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice);
        void display(std::shared_ptr<Item> item, std::ostream& ostr);
        void display(std::shared_ptr<Slide> slide, std::ostream& ostr);

    private:
        void visitItem(const Item& item) override final;
        void visitItemGroup(const ItemGroup& itemGroup) override final;
        void takeOstream(std::ostream& ostr);
    
    private:
        std::shared_ptr<ShapeLibrary> shapeLib_;
        std::ostream* ostr_;
};

}

#endif // RENDERERR_HPP


/*
public:
    Renderer(std::ostream& ostr);
    void draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice);
    void display(std::shared_ptr<ItemInterface> item);

private:
    std::ostream& ostr_;  // Hold the ostream here

    void visitItem(const Item& item) override final;
    void visitItemGroup(const ItemGroup& itemGroup) override final;
    
    // Add display methods for Item and ItemGroup
    void displayItem(const Item& item);
    void displayItemGroup(const ItemGroup& itemGroup);
*/