#ifndef SHAPE_BASE_HPP
#define SHAPE_BASE_HPP

#include "../IShape.hpp"
#include "../ITextDisplayable.hpp"
#include "../IVisualDisplayable.hpp"
#include "../../Data/Item.hpp"
#include "../../Data/IItemVisitor.hpp"

#include <ostream>
#include <memory>

namespace ren {

///NOTE: if I put the commented part in ShapeBase, the dynamic cast fails, that's why it's in the derived classes

using Attributes = dat::Attributes;

class ShapeBase : public IShape, public ITextDisplayable, public IVisualDisplayable {
    public:
        void display(std::ostream& output, std::shared_ptr<Item> item) override final;

    /*public:
        void setType(std::string type);
        void setBBox(BoundingBox bbox);
        void setAttrs(Attributes attrs);
        
    private:
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;*/
};

}
#endif // SHSPE_BASE_HPP