#include "AddCommand.hpp"
#include "../../Data/Item.hpp"

int AddCommand::itemID_ = 0;

AddCommand::AddCommand(const Map& info) :
    infoMap_(info)
{}

void AddCommand::execute() {
    const std::string type = defs::toStr(infoMap_["-type"]); // definitions is included
    std::shared_ptr<Action> action;

    if (isTypeItem(type)) {
        auto idx = defs::toInt(infoMap_["-idx"]);
        auto slide = Application::getDocument().getSlide(idx);
        std::string type = defs::toStr(infoMap_["-type"]);
        BoundingBox bbox = createBoundingBox();
        Attributes attrs(getRemainingPairs());
        auto item = std::make_shared<Item>(type, ++itemID_, bbox, attrs);
        action = std::make_shared<AddItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = std::make_shared<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }
}

BoundingBox AddCommand::createBoundingBox() {
    double l = defs::toDouble(infoMap_["-l"]); 
    double t = defs::toDouble(infoMap_["-t"]); 
    double r = defs::toDouble(infoMap_["-r"]); 
    double b = defs::toDouble(infoMap_["-b"]); 
    BoundingBox bbox = {{l, t}, {r, b}};
    return bbox;
}

Map AddCommand::getRemainingPairs() {
    Map remainingPairs;
    for (auto& pair : infoMap_) {
        auto key = pair.first;
        if (key != "-l" && key != "-t" && key != "-r" && key != "-b" && key != "-type" && key != "-idx") {
            auto value = pair.second;
            remainingPairs[key] = value;
        }
    }
    return remainingPairs;
}