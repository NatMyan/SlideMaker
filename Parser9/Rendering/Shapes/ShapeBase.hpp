#ifndef SHAPE_BASE_HPP
#define SHAPE_BASE_HPP

#include "IShape.hpp"
#include "ITextDisplayable.hpp"
#include "../../Data/Item.hpp"
#include "../../Data/IItemVisitor.hpp"

#include <ostream>
#include <memory>

namespace ren {

class ShapeBase : public IShape, public ITextDisplayable {
    public:
        std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override final;
        void display(std::ostream& output, std::shared_ptr<Item> item) override final;

    public:
        void setType(std::string type);
        void setBBox(BoundingBox bbox);
        void setAttrs(Attributes attrs);
        
    private:
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;
};

}
#endif // SHSPE_BASE_HPP