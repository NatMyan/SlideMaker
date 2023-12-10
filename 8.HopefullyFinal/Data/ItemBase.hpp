#ifndef ITEM_BASE_HPP
#define ITEM_BASE_HPP

class ItemBase {    
    public:
        virtual int getID() const = 0;

        virtual std::string getType() const = 0;
        virtual void setType(std::string type) = 0; 

        virtual BoundingBox getBoundingBox() const = 0;
        virtual void setBoundingBox(BoundingBox bbox) = 0;
        
        virtual Value getAttribute(Key key) const = 0;
        virtual void setAttribute(Key key, Value value) = 0;

        virtual Attributes getAttributes() const = 0;
        virtual void setAttributes(Attributes attrs) = 0;
};

#endif // ITEM_BASE_HPP