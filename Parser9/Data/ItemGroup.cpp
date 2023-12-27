#include "ItemGroup.hpp"
#include "Item.hpp"

#include <unordered_set>

namespace dat {

ItemGroup::ItemGroup(std::string type, int id, BoundingBox bbox, Attributes attrs) :
    id_(id),
    bbox_(bbox),
    attrs_(attrs)
{
    if (type.find("Group") == std::string::npos) { type_ = type + "Group"; }
    else { type_ = type; }

    for (const auto& pair : attrs_) {
        const auto key = pair.first;
        attrStates_.at(key) = true;
    }

    setAbsentAttrs();
}

ItemGroup::ItemGroup(int id, BoundingBox bbox, Attributes attrs) :
    type_("itemGroup"),
    id_(id),
    bbox_(bbox),
    attrs_(attrs)
{
    for (const auto& pair : attrs_) {
        const auto key = pair.first;
        attrStates_.at(key) = true;
    }
    
    setAbsentAttrs();
}

void ItemGroup::setAbsentAttrs() {
    initAbsentAttrs("-lstyle", Value(std::string("straight")));
    initAbsentAttrs("-angle", Value(0));
    initAbsentAttrs("-fcolour", Value(std::string("black")));
    initAbsentAttrs("-lcolour", Value(std::string("green")));
    initAbsentAttrs("-lwidth", Value(1));
    initAbsentAttrs("-text", Value(std::string("")));
    initAbsentAttrs("-tcolour", Value(std::string("black")));
    initAbsentAttrs("-tsize", Value(12));
    initAbsentAttrs("-tfont", Value(std::string("Arial")));

    if (type_ == std::string("polygonGroup") || type_ == std::string("polygon")) {
        initAbsentAttrs("-sideCount", Value(3));
    }
}

void ItemGroup::initAbsentAttrs(Key key, Value val) {
    try { attrs_.getValue(key); }
    catch (const Exception& e) {
        attrs_.setPair(key, val);
        attrStates_.at(key) = true;
    }
}

void ItemGroup::accept(std::shared_ptr<IItemVisitor> visitor) {
    visitor->visitItemGroup(*this);
}

void ItemGroup::addItem(std::shared_ptr<Item> itemPtr) {
    items_.push_back(itemPtr);
    updateBoundingBox(itemPtr->getBoundingBox());
}

void ItemGroup::insertItem(std::shared_ptr<Item> itemPtr, int index) { 
    items_.insert(items_.begin() + index, itemPtr); 
}

void ItemGroup::removeItem(int id) {
    auto conditionToRemove = [id](const std::shared_ptr<Item>& item) { return item->getID() == id; };
    auto iterToRemove = std::remove_if(items_.begin(), items_.end(), conditionToRemove);
    if (iterToRemove != items_.end()) { items_.erase(iterToRemove, items_.end()); }

    for (auto item : items_) { updateBoundingBox(item->getBoundingBox()); }
}

int ItemGroup::getID() const {
    return id_;
}

BoundingBox ItemGroup::getBoundingBox() const {
    return bbox_;
}

void ItemGroup::setBoundingBox(const BoundingBox& bbox) {
    bbox_ = bbox;
}

Value ItemGroup::getAttribute(const Key& key) const {
    if (attrStates_.at(key)) { 
        try { return attrs_.getValue(key); }
        catch (const Exception& e) { throw InvalidAttributeException("Pair not found with key: " + key); }
    }
    throw InvalidAttributeException("Not all items have the same attribute with key: " + key);
}

void ItemGroup::setAttribute(const Key& key, const Value& value) {
    attrs_.setPair(key, value);
    attrStates_.at(key) = true;
}

Attributes ItemGroup::getAttributes() const {
    auto allTrue = std::all_of(attrStates_.begin(), attrStates_.end(), [](const auto& pair) { return pair.second; });
    if (allTrue) { return attrs_; }
    throw InvalidAttributeException("Not all attributes are the same for item group");
}

void ItemGroup::setAttributes(const Attributes& attrs) {
    for (auto pair : attrs) {
        auto [key, value] = pair;
        attrs_.setPair(key, value);
        attrStates_.at(key) = true;
    }
}

std::string ItemGroup::getType() {
    std::unordered_set<std::string> uniqueTypes;
    for (const auto& item : items_) { uniqueTypes.insert(item->getType()); }
    if (uniqueTypes.size() == 1) { type_ = std::string(*uniqueTypes.begin() + "Group"); } 
    
    return type_;
}

void ItemGroup::setType(const std::string& type) { // change all the types into 1 type
    for (auto item : items_) {
        item->setType(type);
    }
}

std::shared_ptr<Item> ItemGroup::getItem(int id) const {
    auto condition = [id](const std::shared_ptr<Item>& item) { return item->getID() == id; };
    auto item_iter = std::find_if(items_.begin(), items_.end(), condition);
    if (item_iter != items_.end()) { return *item_iter; }
    return nullptr;
}

size_t ItemGroup::getItemCount() {
    return items_.size() - 1;
}

ItemGroup::item_iterator ItemGroup::begin() {
    return items_.begin();
}

ItemGroup::item_iterator ItemGroup::end() {
    return items_.end();
}

ItemGroup::const_item_iterator ItemGroup::begin() const {
    return items_.cbegin();
}

ItemGroup::const_item_iterator ItemGroup::end() const {
    return items_.cend();
}

void ItemGroup::updateBoundingBox(const BoundingBox& bbox) {
    if (bbox.first.first > bbox_.first.first) bbox_.first.first = bbox.first.first;
    if (bbox.first.second > bbox_.first.second) bbox_.first.second = bbox.first.second;
    if (bbox.second.first > bbox_.second.first) bbox_.second.first = bbox.second.first;
    if (bbox.second.second > bbox_.second.second) bbox_.second.second = bbox.second.second;
}

}

/*std::shared_ptr<Item> ItemGroup::getTopItem() const {
    return items_.back();
}*/

/*std::string ItemGroup::getType() const {
    for (auto i = 0; i < items_.size(); ++i) {
        for (auto j = 0; j < items_.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (items_.at(i) != items_.at(j)) {
                return type_;
            }
        }
    }
    return (type_ + std::string{"Group"});
}*/