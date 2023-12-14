#include "ItemGroup.hpp"
#include "Item.hpp"

ItemGroup::ItemGroup(int id, BoundingBox bbox, Attributes attrs) :
    type_("itemGroup"),
    id_(id),
    bbox_(bbox),
    attrs_(attrs)
{
    for (const auto& pair : attrs_) {
        const auto key = pair.first;
        attrStates_[key] = false;
    }
}

void ItemGroup::accept(std::unique_ptr<IItemVisitor> visitor) {
    visitor->visitItemGroup(std::shared_ptr<ItemGroup>(this));
}

void ItemGroup::addItem(std::shared_ptr<Item> itemPtr) {
    items_.push_back(itemPtr);
    updateBoundingBox(itemPtr->getBoundingBox());
}

void ItemGroup::insertItem(std::shared_ptr<Item> itemPtr, int index) { 
    items_.insert(items_.begin() + index, itemPtr); 
}

void ItemGroup::removeItem(int id) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if ((*it)->getID() == id) {
            items_.erase(it);
            continue;
        }
        updateBoundingBox((*it)->getBoundingBox()); 
        ///NOTE: this is inefficient, change if time
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
    auto allTrue = std::all_of(attrStates_.begin(), attrStates_.end(), [](const auto& pair) { return pair.second; });
    if (allTrue)
        return attrs_.getValue(key);
    return Value();
    // } 
}

void ItemGroup::setAttribute(Key key, Value value) {
    attrs_.setPair(key, value);
    attrStates_[key] = true;
}

Attributes ItemGroup::getAttributes() const {
    auto allTrue = std::all_of(attrStates_.begin(), attrStates_.end(), [](const auto& pair) { return pair.second; });
    if (allTrue)
        return attrs_;
    return Attributes();
}

void ItemGroup::setAttributes(Attributes attrs) {
    for (auto pair : attrs) {
        auto [key, value] = pair;
        attrs_.setPair(key, value);
        attrStates_[key] = true;
        // auto key = pair.first;
        // auto value = pair.second;
    }
}

std::string ItemGroup::getType() const {
    return type_;
}

/*void ItemGroup::setType(std::string type) { // change all the types into 1 type
    for (auto item : items_) {
        item->setType(type);
    }
}*/

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

void ItemGroup::updateBoundingBox(const BoundingBox& bbox) {
    if (bbox.first.first > bbox_.first.first) bbox_.first.first = bbox.first.first;
    if (bbox.first.second > bbox_.first.second) bbox_.first.second = bbox.first.second;
    if (bbox.second.first > bbox_.second.first) bbox_.second.first = bbox.second.first;
    if (bbox.second.second > bbox_.second.second) bbox_.second.second = bbox.second.second;
}