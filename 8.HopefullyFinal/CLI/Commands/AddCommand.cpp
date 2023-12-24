#include "AddCommand.hpp"
#include "../../Data/Item.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

#include <iostream>

AddCommand::AddCommand(const Map& info) :
    infoMap_(info)
{}

void AddCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;

    if (isItem()) {
        auto idx = defs::toInt(infoMap_["-idx"]);
        auto slide = app->getDocument()->getSlide(idx);
        if (slide) {
            auto item = createTheItem();
            action = std::make_shared<AddItemAction>(slide, item);
        }
    }
    else if (isSlide()) {
        auto doc = app->getDocument();
        auto slide = std::make_shared<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }

    dir->runAction(action);
}

BoundingBox AddCommand::createTheBoundingBox() {
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

std::shared_ptr<Item> AddCommand::createTheItem() {
    static int itemID = 1;
    std::string type = defs::toStr(infoMap_["-type"]);
    BoundingBox bbox = createTheBoundingBox();
    Attributes attrs(getRemainingPairs());
    return std::make_shared<Item>(type, ++itemID, bbox, attrs);
}

bool AddCommand::isArgFound(const std::string& argName) {
    return infoMap_.find(argName) != infoMap_.end();
}

bool AddCommand::isSlide() {
    return !isArgFound("-idx");
}

bool AddCommand::isItem() {
    return isArgFound("-idx");
}