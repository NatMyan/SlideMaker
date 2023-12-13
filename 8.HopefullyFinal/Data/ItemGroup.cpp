#include "ItemGroup.hpp"
#include "Item.hpp"

ItemGroup::ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs) :
    type_(type),
    id_(id),
    bbox_(bbox),
    attrs_(attrs)
{}

void ItemGroup::accept(std::unique_ptr<IItemVisitor> visitor) {
    visitor->visitItemGroup(std::unique_ptr<ItemGroup>(this));
}

void ItemGroup::addItem(std::shared_ptr<Item> itemPtr) {
    items_.push_back(itemPtr);
}

void ItemGroup::insertItem(std::shared_ptr<Item> itemPtr, int index) { 
    items_.insert(items_.begin() + index, itemPtr); 
}

void ItemGroup::removeItem(int id) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if ((*it)->getID() == id) {
            items_.erase(it);
        }
    }
}

int ItemGroup::getID() const {
    return id_;
}
// void setID(int id);

BoundingBox ItemGroup::getBoundingBox() const {
    return bbox_;
}

void ItemGroup::setBoundingBox(BoundingBox bbox) {
    bbox_ = bbox;
}

///TODO: fix this
Value ItemGroup::getAttribute(Key key) const {
    // if (attrs_.find(key) != attrs_.end()) {
        return attrs_.getValue(key);
    // } 
}

void ItemGroup::setAttribute(Key key, Value value) {
    attrs_.setPair(key, value);
}

Attributes ItemGroup::getAttributes() const {
    return attrs_;
}

void ItemGroup::setAttributes(Attributes attrs) {
    for (auto pair : attrs) {
        auto key = pair.first;
        auto value = pair.second;
        attrs_.setPair(key, value);
    }
}

std::string ItemGroup::getType() const {
    return type_;
}

void ItemGroup::setType(std::string type) { // change all the types into 1 type
    for (auto item : items_) {
        item->setType(type);
    }
}

std::shared_ptr<Item> ItemGroup::getItem(int id) const {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if ((*it)->getID() == id) {
            return (*it);
        }
    } 
}
std::shared_ptr<Item> ItemGroup::getTopItem() const {
    return items_.back();
}

size_t ItemGroup::getItemCount() {
    return items_.size();
}

ItemGroup::ItemIterator ItemGroup::begin() {
    return items_.begin();
}

ItemGroup::ItemIterator ItemGroup::end() {
    return items_.end();
}