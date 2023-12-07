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
        auto idx = int(defs::toInt(infoMap_["-idx"]));
        auto slide = Application::getDocument().getSlide(idx);
        std::string type = defs::toStr(infoMap_["-type"]);

        double l = defs::toDouble(infoMap_["-l"]); 
        double t = defs::toDouble(infoMap_["-t"]); 
        double r = defs::toDouble(infoMap_["-r"]); 
        double b = defs::toDouble(infoMap_["-b"]); 
        BoundingBox bbox = {{l, t}, {r, b}};

        Attributes attrs;
        
        auto item = std::shared_ptr<Item>(type, ++itemID_, bbox, attrs);
        action = std::make_shared<AddItemAction>(slide, item);
    }
    else if (isTypeSlide(type)) {
        auto doc = Application::getDocument();
        auto slide = std::shared_ptr<Slide>();
        action = std::make_shared<AddSlideAction>(doc, slide);
    }
}