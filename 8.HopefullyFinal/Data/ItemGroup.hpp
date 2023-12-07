#ifndef ITEM_GROUPP_HPP
#define ITEM_GROUPP_HPP

#include "ItemBase.hpp"
#include "Attributes.hpp"

#include <string>

class ItemGroup {
    public:
        ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs);

    public:
        int getGroupId();
        void setGroupId(int id);

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox bbox);
        
        Value getAttribute(Key key) const;
        void setAttribute(Key key, Value value);
        
        Attributes getAttributes() const;
        void setAttributes(Attributes attrs);
        // std::string getTypes() const;
        // void setType(std::string type);

    private:
        std::string type_;
        int id_; 
        BoundingBox bbox_; 
        Attributes attrs_;
};

#endif // ITEM_GROUPP_HPP