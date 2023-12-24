#include "Renderer.hpp"

#include <iostream>

Renderer::Renderer() :
    shapeLib_(std::make_shared<ShapeLibrary>())
{}

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice) {
    QPainter* painter = new QPainter;
    // std::cout << "QPianter" << std::endl;

    painter->begin(paintDevice);
    // std::cout << "QPianter begin" << std::endl;
    for (auto it = slide->getItemGroup()->begin(); it != slide->getItemGroup()->end(); ++it) {
        // std::cout << "iterating" << std::endl;
        auto item = (*it);
        // std::cout << "iterator" << std::endl;
        std::shared_ptr<IShape> shape = shapeLib_->getShape(item);
        // std::cout << "get shape" << std::endl;
        if (shape) {
            std::shared_ptr<IVisualDisplayable> ptr = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
            // std::cout << "dynamic cast" << std::endl;
            if (ptr) {
                ptr->draw(painter, item);
                // std::cout << "draw" << std::endl;
            }
            // else {
                // std::cout << "dammit" << std::endl;
            // }
        }
        // else {
            // std::cout << "shape is nullptr rip" << std::endl;
        // }
    }
    painter->end();
    // std::cout << "painter end" << std::endl;
}

void Renderer::display(std::shared_ptr<Item> item, std::ostream& ostr) {
    takeOstream(ostr);
    visitItem(*item);
    item->accept(*this);
}

void Renderer::display(std::shared_ptr<Slide> slide, std::ostream& ostr) {
    takeOstream(ostr);
    visitItemGroup(*(slide->getItemGroup()));
    slide->getItemGroup()->accept(*this);
}

void Renderer::visitItem(const Item& item) {
    auto itemPtr = std::make_shared<Item>(item);
    // std::cout << "create item" << std::endl;
    std::shared_ptr<IShape> shape = shapeLib_->getShape(itemPtr);
    // std::cout << "get shape" << std::endl;
    auto ptr = std::dynamic_pointer_cast<ITextDisplayable>(shape);
    // std::cout << "dynamic cast" << std::endl;
    if (ostr_) {
        // std::cout << "ostr works" << std::endl;
        if (ptr) {
            // std::cout << "ptr" << std::endl;
            ptr->display(*ostr_, itemPtr);
        }
        else {
            // std::cout << "no ptr" << std::endl;
        }
    }
    else {
        // std::cout << "ostr doesn't work" << std::endl;
    }
}

void Renderer::visitItemGroup(const ItemGroup& itemGroup) {
    auto itemgroupPtr = std::make_shared<ItemGroup>(itemGroup);
    for (auto it = itemgroupPtr->begin(); it != itemgroupPtr->end(); ++it) {
        auto item = *it;
        visitItem(*item);
    }
}

void Renderer::takeOstream(std::ostream& ostr) {
    ostr_ = &ostr;
}


/*
// Inside Renderer.hpp
class Renderer : public IItemVisitor {
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
};

// Inside Renderer.cpp
Renderer::Renderer(std::ostream& ostr) : ostr_(ostr) {}

void Renderer::display(std::shared_ptr<ItemInterface> item) {
    item->accept(*this);
}

void Renderer::visitItem(const Item& item) {
    displayItem(item);
}

void Renderer::visitItemGroup(const ItemGroup& itemGroup) {
    displayItemGroup(itemGroup);
}

// Implement your displayItem and displayItemGroup methods
void Renderer::displayItem(const Item& item) {
    // Implement how to display an Item
    ostr_ << "Displaying Item: " << item.getDescription() << std::endl;
}

void Renderer::displayItemGroup(const ItemGroup& itemGroup) {
    // Implement how to display an ItemGroup
    ostr_ << "Displaying ItemGroup: " << itemGroup.getDescription() << std::endl;
}*/

/*void Renderer::display(std::shared_ptr<ItemInterface> item, std::ostream& ostr) {
    std::shared_ptr<IShape> shape = shapeLib_->getShape(item);
    auto ptr = std::dynamic_pointer_cast<ITextDisplayable>(shape);
    ptr->display(item, ostr);
}

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice) {
    QPainter* painter = new QPainter;
    painter->begin(paintDevice);
    std::shared_ptr<IShape> shape = shapeLib_->getShape();
    auto ptr = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
    ptr->draw(painter, shape);
    painter->end();
}*/
