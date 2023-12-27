#ifndef ITEM_HPP
#define ITEM_HPP

#include "Attributes.hpp"
#include "IItem.hpp"
#include "IItemVisitor.hpp"
#include "../zhelpers/Exception.hpp"

namespace dat {

class Item : public IItem {    
    struct InvalidAttributeException : public Exception { using Exception::Exception; };

    public:
        explicit Item(std::string type, ID id, BoundingBox bbox, Attributes attrs);

    public:
        void accept(std::shared_ptr<IItemVisitor> visitor);
        
        ID getID() const override;

        std::string getType() override;
        void setType(const std::string& type) override;
        
        BoundingBox getBoundingBox() const override;
        void setBoundingBox(const BoundingBox& bbox) override;

        Value getAttribute(const Key& key) const override;
        void setAttribute(const Key& key, const Value& value) override;

        Attributes getAttributes() const override;
        void setAttributes(const Attributes& attrs) override;

    private:
        void initAbsentAttrs(const Key& key, const Value& val);
        void setAbsentAttrs();

    private:
        ID id_;
        std::string type_;
        BoundingBox bbox_; 
        Attributes attrs_;
};

}

#endif // ITEM_HPP