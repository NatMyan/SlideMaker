#include "IShapeRenderer.hpp"

IShapeRenderer::IShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr) :
    itemPtr_(itemPtr),
    idx_(idx)     
{}

void IShapeRenderer::print(std::ostream& stream) {
    stream << idx_ << ": " << itemPtr_->getID() << " " << itemPtr_->getType() << " ";
    auto pos = itemPtr_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
    stream << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";
    auto attrs = itemPtr_->getAttributes();
    for (const auto& attr : attrs) {
        stream << attrs.getKey(attr);
        if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
            stream << attr.get<int>() << " ";
        }
        else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
            stream << attr.get<double>() << " ";
        }
        else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
            stream << attr.get<std::string>() << " ";
        }
    }
    stream << std::endl;
}