#include "AddCommand.hpp"
#include "../../Data/Item.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

#include <iostream>

namespace cli {

AddCommand::AddCommand(const Map& info) :
    infoMap_(info)
{}

void AddCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    auto doc = app->getDocument();
    std::shared_ptr<IAction> action = nullptr;

    if (isItem()) {
        ID idx;
        try { idx = defs::toInt(infoMap_["-idx"]); }
        catch (const std::exception& e) { idx = dir->getActiveSlideIdx(); }

        auto slide = doc->getSlide(idx);
        if (slide) {
            auto item = createTheItem();
            action = std::make_shared<AddItemAction>(slide, item);
        }
        else { throw InvalidSlideException("Slide is nullptr"); }
    }
    else if (isSlide()) {
        auto slide = std::make_shared<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }

    if (action) { dir->runAction(action); }
    else { throw InvalidActionException("Action is nullptr"); }
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
    static int itemID = 0;
    std::string type = defs::toStr(infoMap_["-type"]);
    BoundingBox bbox = createTheBoundingBox();
    Attributes attrs(getRemainingPairs());
    return std::make_shared<Item>(type, ++itemID, bbox, attrs);
} 

bool AddCommand::isSlide() {
    return ((infoMap_.find("-type") != infoMap_.end()) && (infoMap_["-type"] == Value(std::string("slide"))));
}

bool AddCommand::isItem() {
    return !isSlide();
}

}

// catch (const Exception& e) { idx = dir->getActiveSlideIdx(); }
// catch (const std::out_of_range& o) { idx = dir->getActiveSlideIdx(); }